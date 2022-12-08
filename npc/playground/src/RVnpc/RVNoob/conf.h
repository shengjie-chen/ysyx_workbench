/*
 * @Author: Shengjie Chen chenshengjie1999@126.com
 * @Date: 2022-11-05 16:32:16
 * @LastEditors: Shengjie Chen chenshengjie1999@126.com
 * @LastEditTime: 2022-12-08 19:16:28
 * @FilePath: /npc/playground/src/RVnpc/RVNoob/conf.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __MACRO_CONF__
#define __MACRO_CONF__

// ---------------------------->switch

// #define CONFIG_ITRACE
// #define CONFIG_FTRACE
#define CONFIG_MTRACE

#define CONFIG_DIFFTEST

// 1M --> 1.6GB
#define CONFIG_DUMPVCD
#define CONFIG_DUMPSTART 30000

// ---------------------------->switch end


// #define BIGPROGRAM

// #ifdef BIGPROGRAM
// #define BIGPROGRAMDEBUG
// #define CONFIG_DIFFTEST
// #endif


// #ifndef BIGPROGRAM
// #define CONFIG_ITRACE
// #define CONFIG_FTRACE
// #define CONFIG_MTRACE
// #define CONFIG_DUMPVCD
// #define CONFIG_DIFFTEST
// #define CONFIG_DUMPSTART 0
// #endif

// #ifdef BIGPROGRAMDEBUG
// // #define CONFIG_MTRACE
// #define CONFIG_ITRACE
// #define CONFIG_FTRACE
// #define CONFIG_DUMPVCD
// #define CONFIG_DUMPSTART 0
// // #define CONFIG_DUMPSTART 11200000
// #endif

#define CONFIG_ISA64 1
#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000

#define CONFIG_VGA_SHOW_SCREEN 1
#define CONFIG_VGA_SIZE_400x300 1

#endif