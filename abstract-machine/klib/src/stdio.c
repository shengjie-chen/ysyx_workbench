#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdarg.h>

int int2char(int d, char *out);

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int uint2char(uint32_t d, char *out);
int hex2char(uint32_t d, char *out);
int lint2char(long int d, char *out);
int lhex2char(uint64_t d, char *out);
int luint2char(uint64_t d, char *out);

#define MAX_LEN_PRINT 10240
int printf(const char *fmt, ...) {
    char out[MAX_LEN_PRINT];
    va_list ap;
    va_start(ap, fmt);
    int j = vsprintf(out, fmt, ap);
    if (j > MAX_LEN_PRINT) {
        printf("printf char array out of bounds, change macro!\n");
    }
    va_end(ap);
    if (j >= 0) {
        for (int i = 0; i < j; i++) {
            putch(out[i]);
        }
    }
    return j;
}
static void print_char(char cc, int *j, char *out) {
    out[*j] = cc;
    *j = *j + 1;
}

static void print_int(int dd, int *count, int *j, char *out) {
    if (dd == 0) {
        *count = 1;
        out[*j] = 48;
    } else {
        *count = int2char(dd, &out[*j]);
    }
    *j += *count;
}

static void print_long(long int dd, int *count, int *j, char *out, char type) {
    if (dd == 0) {
        *count = 1;
        out[*j] = 48;
    } else {
        switch (type) {
        case 'd': {
            *count = lint2char(dd, &out[*j]);
            break;
        }
        case 'x': {
            *count = lhex2char(dd, &out[*j]);
            break;
        }
        case 'u': {
            *count = luint2char(dd, &out[*j]);
            break;
        }
        default: {
            *count = 0;
        }
        }
    }
    *j += *count;
}

#ifdef __SUPPORT_FLOAT__
static void print_float(double ff, int *count, int *j, char *out) {
    long int ff_int = ff;
    long int ff_dec = (ff > 0 ? 1 : -1) * (ff - ff_int) * 1000000;
    if (ff < 0 && ff_int == 0) {
        print_char('-', j, out);
    }
    print_long(ff_int, count, j, out, 'd');
    print_char('.', j, out);
    if (ff_dec != 0) {
        for (int i = ff_dec; i < 100000; i *= 10) {
            print_char('0', j, out);
        }
        print_long(ff_dec, count, j, out, 'u');
    } else {
        for (int i = 0; i < 6; i++) {
            print_char('0', j, out);
        }
    }
}
#endif

int vsprintf(char *out, const char *fmt, va_list ap) {
    int i = 0; // fmt
    int j = 0; // out
    while (fmt[i] != '\0') {
        if (fmt[i] != '%') {
            out[j] = fmt[i];
            i++;
            j++;
            continue;
        }
        i++;
        int count;
        switch (fmt[i]) {
        case 'c': // 得到一个字符
        {
            char cc;
            cc = (char)va_arg(ap, int);
            print_char(cc, &j, out);
            break;
        }
        case 'd': // 得到一个整数
        {
            int dd;
            dd = (int)va_arg(ap, int);
            print_int(dd, &count, &j, out);
            break;
        }
        case 'f': // 得到一个float/double数
        {
#ifdef __SUPPORT_FLOAT__
            double ff;
            ff = va_arg(ap, double);
            print_float(ff, &count, &j, out);
            break;
#endif
            printf("[warming]not support print float, please open macro!");
        }
        case 'x': // 得到一个0x数
        {
            int xx;
            xx = (uint32_t)va_arg(ap, uint32_t);
            print_char('0', &j, out);
            print_char('x', &j, out);
            if (xx == 0) {
                count = 1;
                out[j] = 48;
            } else {
                count = hex2char(xx, &out[j]);
            }
            j += count;
            break;
        }
        case 's': // 得到一个字符串
        {
            char *ss;
            count = 0;
            ss = va_arg(ap, char *);
            if (ss == NULL) {
                return -1;
            }
            while ((out[j++] = *ss++) != 0)
                ;
            j--;
            break;
        }
        case 'p': // 得到一个address
        case 'u': {
            int pp;
            pp = (uint32_t)va_arg(ap, uint32_t);
            if (pp == 0) {
                count = 1;
                out[j] = 48;
            } else {
                count = uint2char(pp, &out[j]);
            }
            j += count;
            break;
        }
        case 'l': // 得到一个long number
        {
            i++;
            switch (fmt[i]) {
            case 'd': // 得到一个long整数
            {
                long int dd;
                dd = (long int)va_arg(ap, long int);
                print_long(dd, &count, &j, out, 'd');
                break;
            }
            case 'u': {
                uint64_t pp;
                pp = (uint64_t)va_arg(ap, uint64_t);
                print_long(pp, &count, &j, out, 'u');
                break;
            }
            case 'x': // 得到一个0x数
            {
                uint64_t xx;
                xx = (uint64_t)va_arg(ap, uint64_t);
                print_char('0', &j, out);
                print_char('x', &j, out);
                print_long(xx, &count, &j, out, 'x');
                break;
            }
            }
        }
        default: {
        }
        }
        i++;
    }
    out[j] = '\0';
    return j;
}

int lint2char(long int d, char *out) {
    int count = 0;
    long int n = d;
    char m[20];
    if (d < 0) {
        *out++ = '-';
        n = -d;
    }
    while (n != 0) {
        m[count] = n % 10 + 48;
        n /= 10;
        ++count;
    }
    int i;
    for (i = 0; i < count; i++) {
        *(out + i) = m[count - i - 1];
    }
    if (d < 0) {
        return count + 1;
    } else {
        return count;
    }
}

int uint2char(uint32_t d, char *out) {
    int count = 0;
    uint32_t n = d;
    char m[10];
    while (n != 0) {
        m[count] = n % 10 + 48;
        n /= 10;
        ++count;
    }
    int i;
    for (i = 0; i < count; i++) {
        *(out + i) = m[count - i - 1];
    }
    return count;
}

int hex2char(uint32_t d, char *out) {
    int count = 0;
    uint32_t n = d;
    char m[10];
    while (n != 0) {
        int x = n % 16;
        if (x < 10) {
            m[count] = x + 48;

        } else {
            m[count] = n % 16 + 55;
        }
        n /= 16;
        ++count;
    }
    int i;
    for (i = 0; i < count; i++) {
        *(out + i) = m[count - i - 1];
    }
    return count;
}

int luint2char(uint64_t d, char *out) {
    int count = 0;
    uint64_t n = d;
    char m[20];
    while (n != 0) {
        m[count] = n % 10 + 48;
        n /= 10;
        ++count;
    }
    int i;
    for (i = 0; i < count; i++) {
        *(out + i) = m[count - i - 1];
    }
    return count;
}

int lhex2char(uint64_t d, char *out) {
    int count = 0;
    uint64_t n = d;
    char m[20];
    while (n != 0) {
        int x = n % 16;
        if (x < 10) {
            m[count] = x + 48;

        } else {
            m[count] = n % 16 + 55;
        }
        n /= 16;
        ++count;
    }
    int i;
    for (i = 0; i < count; i++) {
        *(out + i) = m[count - i - 1];
    }
    return count;
}

int sprintf(char *out, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int j = vsprintf(out, fmt, ap);
    va_end(ap);
    return j;
}

int snprintf(char *out, size_t n, const char *fmt, ...) { panic("Not implemented"); }

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) { panic("Not implemented"); }

#endif

int int2char(int d, char *out) {
    int count = 0;
    int n = d;
    char m[10];
    if (d < 0) {
        *out++ = '-';
        n = -d;
    }
    while (n != 0) {
        m[count] = n % 10 + 48;
        n /= 10;
        ++count;
    }
    int i;
    for (i = 0; i < count; i++) {
        *(out + i) = m[count - i - 1];
    }
    if (d < 0) {
        return count + 1;
    } else {
        return count;
    }
}