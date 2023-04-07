#ifndef _0_H
#define _0_H
#define ABS_1 1e-5

int comp(int, void *, void *);
char tolower_(char c);

// X64 Assume
enum _ctype{
    VOID,
    UCHAR,CHAR,
    USHORT,SHORT,
    UINT,INT,
    ULONG,LONG,
    ULONGLONG,LONGLONG,
    FLOAT,
    DOUBLE,
    LONGDOUBLE
};

#ifdef COMPILE_TEST
void test_c_type_byte();
#endif 

#endif 