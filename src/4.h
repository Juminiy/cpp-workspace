#include <stdio.h>
#include <stddef.h>
extern void cmdsh_scanf(int format_argc, int variant_argc, const char *format, ...)
            __attribute__((format(scanf, format_argc, variant_argc)));
extern void error_printf(int format_argc, int variant_argc, const char *format, ...)
            __attribute__((format(printf, format_argc, variant_argc)));

extern void never_ret()
            __attribute__((noreturn));

extern __int32_t const_ret()
                __attribute__((const));