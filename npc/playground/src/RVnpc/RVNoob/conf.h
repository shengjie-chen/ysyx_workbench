#ifndef __MACRO_CONF__
#define __MACRO_CONF__

#define BIGPROGRAM

#ifndef BIGPROGRAM
#define CONFIG_ITRACE
#define CONFIG_FTRACE
#define CONFIG_MTRACE
#define CONFIG_DUMPVCD
#define CONFIG_DUMPSTART 0
#endif

#ifdef BIGPROGRAM
#define CONFIG_DIFFTEST
#define CONFIG_DUMPVCD
#define CONFIG_DUMPSTART 4000000
#endif

#define CONFIG_ISA64 1
#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000

#endif