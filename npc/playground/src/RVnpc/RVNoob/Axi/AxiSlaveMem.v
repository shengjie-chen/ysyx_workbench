
`timescale 1 ns / 1 ps

	module AxiSlaveMem #
	(
		// Width of ID for for write address, write data, read address and read data
		parameter integer C_S_AXI_ID_WIDTH	= 4,
		// Width of S_AXI data bus
		parameter integer C_S_AXI_DATA_WIDTH	= 64,
		// Width of S_AXI address bus
		parameter integer C_S_AXI_ADDR_WIDTH	= 32
	)
	(
		input wire  S_AXI_ACLK,
		input wire  S_AXI_ARESETN,

		input   wire                            S_AXI_AWVALID ,
		output  wire                            S_AXI_AWREADY ,
		input   wire [C_S_AXI_ID_WIDTH-1 : 0]   S_AXI_AWID    ,
		input   wire [C_S_AXI_ADDR_WIDTH-1 : 0] S_AXI_AWADDR  ,
		input   wire [7 : 0]                    S_AXI_AWLEN   ,
		input   wire [2 : 0]                    S_AXI_AWSIZE  ,
		input   wire [1 : 0]                    S_AXI_AWBURST ,

		input   wire                                S_AXI_WVALID    ,
		output  wire                                S_AXI_WREADY    ,
		input   wire [C_S_AXI_DATA_WIDTH-1 : 0]     S_AXI_WDATA     ,
		input   wire [(C_S_AXI_DATA_WIDTH/8)-1 : 0] S_AXI_WSTRB     ,
		input   wire                                S_AXI_WLAST     ,

		output  wire                                S_AXI_BVALID    ,
		input   wire                                S_AXI_BREADY    ,
		output  wire [C_S_AXI_ID_WIDTH-1 : 0]       S_AXI_BID       ,
		output  wire [1 : 0]                        S_AXI_BRESP     ,

		input   wire                                S_AXI_ARVALID   ,
		output  wire                                S_AXI_ARREADY   ,
		input   wire [C_S_AXI_ID_WIDTH-1 : 0]       S_AXI_ARID      ,
		input   wire [C_S_AXI_ADDR_WIDTH-1 : 0]     S_AXI_ARADDR    ,
		input   wire [7 : 0]                        S_AXI_ARLEN     ,
		input   wire [2 : 0]                        S_AXI_ARSIZE    ,
		input   wire [1 : 0]                        S_AXI_ARBURST   ,

		output  wire                                S_AXI_RVALID    ,
		input   wire                                S_AXI_RREADY    ,
		output  wire [C_S_AXI_ID_WIDTH-1 : 0]       S_AXI_RID       ,
		output  wire [C_S_AXI_DATA_WIDTH-1 : 0]     S_AXI_RDATA     ,
		output  wire [1 : 0]                        S_AXI_RRESP     ,
		output  wire                                S_AXI_RLAST
	);

	// AXI4FULL signals
	reg [C_S_AXI_ADDR_WIDTH-1 : 0] 		axi_awaddr	 ;
	reg  	                            axi_awready  ;
	reg  	                            axi_wready   ;
	reg [1 : 0] 	                    axi_bresp    ;
	reg  	                            axi_bvalid   ;
	reg [C_S_AXI_ADDR_WIDTH-1 : 0] 		axi_araddr   ;
	reg  	                            axi_arready  ;
	reg [C_S_AXI_DATA_WIDTH-1 : 0] 		axi_rdata    ;
	reg [1 : 0] 	                    axi_rresp    ;
	reg  	                            axi_rlast    ;
	reg  	                            axi_rvalid   ;
	
	// aw_wrap_en determines wrap boundary and enables wrapping
	wire aw_wrap_en;
	// ar_wrap_en determines wrap boundary and enables wrapping
	wire ar_wrap_en;
	// aw_wrap_size is the size of the write transfer, the
	// write address wraps to a lower address if upper address
	// limit is reached
	wire [31:0]  aw_wrap_size ; 
	// ar_wrap_size is the size of the read transfer, the
	// read address wraps to a lower address if upper address
	// limit is reached
	wire [31:0]  ar_wrap_size ; 
	// The axi_awv_awr_flag flag marks the presence of write address valid
	reg axi_awv_awr_flag;
	//The axi_arv_arr_flag flag marks the presence of read address valid
	reg axi_arv_arr_flag; 
	// The axi_awlen_cntr internal write address counter to keep track of beats in a burst transaction
	reg [7:0] axi_awlen_cntr;
	//The axi_arlen_cntr internal read address counter to keep track of beats in a burst transaction
	reg [7:0] axi_arlen_cntr;
	reg [1:0] axi_arburst;
	reg [1:0] axi_awburst;
	reg [7:0] axi_arlen;
	reg [7:0] axi_awlen;


	//local parameter for addressing 32 bit / 64 bit C_S_AXI_DATA_WIDTH
	//ADDR_LSB is used for addressing 32/64 bit registers/memories
	//ADDR_LSB = 2 for 32 bits (n downto 2) 
	//ADDR_LSB = 3 for 42 bits (n downto 3)

	localparam integer ADDR_LSB = (C_S_AXI_DATA_WIDTH/32)+ 1; // 为保证对齐，低ADDR_LSB地址保持0


	// I/O Connections assignments

	assign S_AXI_AWREADY	= axi_awready;
	assign S_AXI_WREADY		= axi_wready;
	assign S_AXI_BRESP		= axi_bresp;
	assign S_AXI_BVALID		= axi_bvalid;
	assign S_AXI_ARREADY	= axi_arready;
	assign S_AXI_RDATA		= axi_rdata;
	assign S_AXI_RRESP		= axi_rresp;
	assign S_AXI_RLAST		= axi_rlast;
	assign S_AXI_RVALID		= axi_rvalid;
	assign S_AXI_BID     	= S_AXI_AWID;
	assign S_AXI_RID     	= S_AXI_ARID;
	assign  aw_wrap_size 	= (C_S_AXI_DATA_WIDTH/8 * (axi_awlen)); 
	assign  ar_wrap_size 	= (C_S_AXI_DATA_WIDTH/8 * (axi_arlen)); 
	assign  aw_wrap_en   	= ((axi_awaddr & aw_wrap_size) == aw_wrap_size)? 1'b1: 1'b0;
	assign  ar_wrap_en   	= ((axi_araddr & ar_wrap_size) == ar_wrap_size)? 1'b1: 1'b0;

	// Implement axi_awready generation

	// axi_awready is asserted for one S_AXI_ACLK clock cycle when both
	// S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_awready is
	// de-asserted when reset is low.

	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_awready <= 1'b0;
	      axi_awv_awr_flag <= 1'b0;
	    end 
	  else
	    begin    
	      if (~axi_awready && S_AXI_AWVALID && ~axi_awv_awr_flag && ~axi_arv_arr_flag)
	        begin
	          // slave is ready to accept an address and
	          // associated control signals
	          axi_awready <= 1'b1;
	          axi_awv_awr_flag  <= 1'b1; 
	          // used for generation of bresp() and bvalid
	        end
	      else if (S_AXI_WLAST && axi_wready)          
	      // preparing to accept next address after current write burst tx completion
	        begin
	          axi_awv_awr_flag  <= 1'b0;
	        end
	      else        
	        begin
	          axi_awready <= 1'b0;
	        end
	    end 
	end       
	// Implement axi_awaddr latching

	// This process is used to latch the address when both 
	// S_AXI_AWVALID and S_AXI_WVALID are valid. 

	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_awaddr <= 0;
	      axi_awlen_cntr <= 0;
	      axi_awburst <= 0;
	      axi_awlen <= 0;
	    end 
	  else
	    begin    
	      if (~axi_awready && S_AXI_AWVALID && ~axi_awv_awr_flag)
	        begin
	          // address latching 
	          axi_awaddr <= S_AXI_AWADDR[C_S_AXI_ADDR_WIDTH - 1:0];  
	           axi_awburst <= S_AXI_AWBURST; 
	           axi_awlen <= S_AXI_AWLEN;     
	          // start address of transfer
	          axi_awlen_cntr <= 0;
	        end   
	      else if((axi_awlen_cntr <= axi_awlen) && axi_wready && S_AXI_WVALID)        
	        begin

	          axi_awlen_cntr <= axi_awlen_cntr + 1;

	          case (axi_awburst)
	            2'b00: // fixed burst 
	            // The write address for all the beats in the transaction are fixed
	              begin
	                axi_awaddr <= axi_awaddr;          
	                //for awsize = 4 bytes (010)
	              end   
	            2'b01: //incremental burst
	            // The write address for all the beats in the transaction are increments by awsize
	              begin
	                axi_awaddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB] <= axi_awaddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB] + 1;
	                //awaddr aligned to 4 byte boundary
	                axi_awaddr[ADDR_LSB-1:0]  <= {ADDR_LSB{1'b0}};   
	                //for awsize = 4 bytes (010)
	              end   
	            2'b10: //Wrapping burst 可以不实现
	            // The write address wraps when the address reaches wrap boundary 
	              if (aw_wrap_en)
	                begin
	                  axi_awaddr <= (axi_awaddr - aw_wrap_size); 
	                end
	              else 
	                begin
	                  axi_awaddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB] <= axi_awaddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB] + 1;
	                  axi_awaddr[ADDR_LSB-1:0]  <= {ADDR_LSB{1'b0}}; 
	                end                      
	            default: //reserved (incremental burst for example)
	              begin
	                axi_awaddr <= axi_awaddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB] + 1;
	                //for awsize = 4 bytes (010)
	              end
	          endcase              
	        end
	    end 
	end       
	// Implement axi_wready generation

	// axi_wready is asserted for one S_AXI_ACLK clock cycle when both
	// S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_wready is 
	// de-asserted when reset is low. 

	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_wready <= 1'b0;
	    end 
	  else
	    begin    
	      if ( ~axi_wready && S_AXI_WVALID && axi_awv_awr_flag)
	        begin
	          // slave can accept the write data
	          axi_wready <= 1'b1;
	        end
	      //else if (~axi_awv_awr_flag)
	      else if (S_AXI_WLAST && axi_wready)
	        begin
	          axi_wready <= 1'b0;
	        end
	    end 
	end       
	// Implement write response logic generation

	// The write response and response valid signals are asserted by the slave 
	// when axi_wready, S_AXI_WVALID, axi_wready and S_AXI_WVALID are asserted.  
	// This marks the acceptance of address and indicates the status of 
	// write transaction.

	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_bvalid <= 0;
	      axi_bresp <= 2'b0;
	    end 
	  else
	    begin    
	      if (axi_awv_awr_flag && axi_wready && S_AXI_WVALID && ~axi_bvalid && S_AXI_WLAST )
	        begin
	          axi_bvalid <= 1'b1;
	          axi_bresp  <= 2'b0; 
	          // 'OKAY' response 
	        end                   
	      else
	        begin
	          if (S_AXI_BREADY && axi_bvalid) 
	          //check if bready is asserted while bvalid is high) 
	          //(there is a possibility that bready is always asserted high)   
	            begin
	              axi_bvalid <= 1'b0; 
	            end  
	        end
	    end
	 end   
	// Implement axi_arready generation

	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_arready <= 1'b0;
	      axi_arv_arr_flag <= 1'b0;
	    end 
	  else
	    begin    
	      if (~axi_arready && S_AXI_ARVALID && ~axi_awv_awr_flag && ~axi_arv_arr_flag)
	        begin
	          axi_arready <= 1'b1;
	          axi_arv_arr_flag <= 1'b1;
	        end
	      else if (axi_rvalid && S_AXI_RREADY && axi_arlen_cntr == axi_arlen)
	      // preparing to accept next address after current read completion
	        begin
	          axi_arv_arr_flag  <= 1'b0;
	        end
	      else        
	        begin
	          axi_arready <= 1'b0;
	        end
	    end 
	end       
	// Implement axi_araddr latching

	//This process is used to latch the address when both 
	//S_AXI_ARVALID and S_AXI_RVALID are valid. 
	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_araddr <= 0;
	      axi_arlen_cntr <= 0;
	      axi_arburst <= 0;
	      axi_arlen <= 0;
	      axi_rlast <= 1'b0;
	    end 
	  else
	    begin    
	      if (~axi_arready && S_AXI_ARVALID && ~axi_arv_arr_flag)
	        begin
	          // address latching 
	          axi_araddr <= S_AXI_ARADDR[C_S_AXI_ADDR_WIDTH - 1:0]; 
	          axi_arburst <= S_AXI_ARBURST; 
	          axi_arlen <= S_AXI_ARLEN;     
	          // start address of transfer
	          axi_arlen_cntr <= 0;
	          axi_rlast <= 1'b0;
	        end   
	      else if((axi_arlen_cntr <= axi_arlen) && axi_rvalid && S_AXI_RREADY)        
	        begin
	         
	          axi_arlen_cntr <= axi_arlen_cntr + 1;
	          axi_rlast <= 1'b0;
	        
	          case (axi_arburst)
	            2'b00: // fixed burst
	             // The read address for all the beats in the transaction are fixed
	              begin
	                axi_araddr       <= axi_araddr;        
	                //for arsize = 4 bytes (010)
	              end   
	            2'b01: //incremental burst
	            // The read address for all the beats in the transaction are increments by awsize
			      begin
	                axi_araddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB] <= axi_araddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB] + 1; 
	                //araddr aligned to 4 byte boundary
	                axi_araddr[ADDR_LSB-1:0]  <= {ADDR_LSB{1'b0}};   
	                //for awsize = 4 bytes (010)
	              end   
	            2'b10: //Wrapping burst
	            // The read address wraps when the address reaches wrap boundary 
	              if (ar_wrap_en) 
	                begin
	                  axi_araddr <= (axi_araddr - ar_wrap_size); 
	                end
	              else 
	                begin
	                axi_araddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB] <= axi_araddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB] + 1; 
	                //araddr aligned to 4 byte boundary
	                axi_araddr[ADDR_LSB-1:0]  <= {ADDR_LSB{1'b0}};   
	                end                      
	            default: //reserved (incremental burst for example)
	              begin
	                axi_araddr <= axi_araddr[C_S_AXI_ADDR_WIDTH - 1:ADDR_LSB]+1;
	                //for arsize = 4 bytes (010)
	              end
	          endcase              
	        end
	      else if((axi_arlen_cntr == axi_arlen) && ~axi_rlast && axi_arv_arr_flag )   
	        begin
	          axi_rlast <= 1'b1;
	        end          
	      else if (S_AXI_RREADY)   
	        begin
	          axi_rlast <= 1'b0;
	        end          
	    end 
	end       
	// Implement axi_arvalid generation

	// axi_rvalid is asserted for one S_AXI_ACLK clock cycle when both 
	// S_AXI_ARVALID and axi_arready are asserted. The slave registers 
	// data are available on the axi_rdata bus at this instance. The 
	// assertion of axi_rvalid marks the validity of read data on the 
	// bus and axi_rresp indicates the status of read transaction.axi_rvalid 
	// is deasserted on reset (active low). axi_rresp and axi_rdata are 
	// cleared to zero on reset (active low).  

	always @( posedge S_AXI_ACLK )
	begin
	  if ( S_AXI_ARESETN == 1'b0 )
	    begin
	      axi_rvalid <= 0;
	      axi_rresp  <= 0;
	    end 
	  else
	    begin    
	      if (axi_arv_arr_flag && ~axi_rvalid)
	        begin
	          axi_rvalid <= 1'b1;
	          axi_rresp  <= 2'b0; 
	          // 'OKAY' response
	        end   
	      else if (axi_rvalid && S_AXI_RREADY)
	        begin
	          axi_rvalid <= 1'b0;
	        end            
	    end
	end    


	reg [C_S_AXI_DATA_WIDTH-1:0] mem_data_out;

	wire mem_rden;
	wire mem_wren;

	assign mem_wren = axi_wready && S_AXI_WVALID ;
	assign mem_rden = axi_arv_arr_flag ; //& ~axi_rvalid
	
	wire [63:0] data_out;
	
	DpiPmem u_DpiPmem(
		.clk    ( S_AXI_ACLK    ),
		.raddr  ( axi_araddr  ),
		.rdata  ( data_out  ),
		.r_pmem ( mem_rden ),

		.waddr  ( axi_awaddr  ),
		.wmask  ( S_AXI_WSTRB  ),
		.wdata  ( S_AXI_WDATA  ),
		.w_pmem  ( mem_wren  )
	);
	
	always @( posedge S_AXI_ACLK )
	begin
		if (mem_rden)
		begin
			mem_data_out <= data_out;
		end   
	end    
				
	//Output register or memory read data

	always @(*)
	begin
	  if (axi_rvalid) 
	    begin
	      // Read address mux
	      axi_rdata <= mem_data_out;
	    end   
	  else
	    begin
	      axi_rdata <= 32'h00000000;
	    end       
	end    

	endmodule
