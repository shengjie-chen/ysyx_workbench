#ifndef __MACRO_CONF__
#define __MACRO_CONF__

// switch
#define BIGPROGRAM

#ifdef BIGPROGRAM
// #define BIGPROGRAMDEBUG
// #define CONFIG_DIFFTEST
#endif

// switch end


#ifndef BIGPROGRAM
#define CONFIG_ITRACE
#define CONFIG_FTRACE
#define CONFIG_MTRACE
#define CONFIG_DUMPVCD
#define CONFIG_DIFFTEST
#define CONFIG_DUMPSTART 0
#endif

#ifdef BIGPROGRAMDEBUG
// 1M --> 1.6GB
#define CONFIG_DUMPVCD
#define CONFIG_DUMPSTART 11200000
#endif

#define CONFIG_ISA64 1
#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000

#endif