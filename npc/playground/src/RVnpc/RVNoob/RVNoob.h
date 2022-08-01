
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

typedef uint64_t word_t;
typedef uint64_t paddr_t;

#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000

#define PG_ALIGN __attribute((aligned(4096)))
#define CONFIG_ISA64 1
#define IFDEF(macro, ...) MUXDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)
#define MUXDEF(macro, X, Y)  MUX_MACRO_PROPERTY(__P_DEF_, macro, X, Y)
#define CONFIG_RT_CHECK 1

#define RESET_VECTOR (CONFIG_MBASE + CONFIG_PC_RESET_OFFSET)
#define CONFIG_PC_RESET_OFFSET 0x0
