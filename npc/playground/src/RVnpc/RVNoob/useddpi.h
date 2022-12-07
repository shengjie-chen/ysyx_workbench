/*
 * @Author: Shengjie Chen chenshengjie1999@126.com
 * @Date: 2022-12-07 22:54:24
 * @LastEditors: Shengjie Chen chenshengjie1999@126.com
 * @LastEditTime: 2022-12-07 22:56:27
 * @FilePath: /npc/playground/src/RVnpc/RVNoob/useddpi.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __USEDDPI_H__
#define __USEDDPI_H__

extern "C" void pmem_read_dpi(long long raddr, long long *rdata);

extern "C" void pmem_write_dpi(long long waddr, long long wdata, char wmask);


#endif