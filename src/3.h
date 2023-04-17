#ifndef _3_H
#define _3_H
#include <stddef.h>
#include <stdio.h>

enum hex_in_dec{
    hex_bin = 2,
    hex_oct = 8,
    hex_dec = 10,
    hex_hex = 16
};
// binary type system
// 0b 0B bin binary
// 0o 0O oct octal
// 0d 0D dec decimal
// 0x 0X hex hexadecimal

// hexa converter
// 2 < - > 8
// 2 < - > 16
// 2 < - > 10 

// malloc from heap, can always be freed
typedef struct c_str_int{
    // 'X'|'x'        -> hex
    // 'D'|'d'|' '|'' -> dec
    // 'O'|'o'        -> oct
    // 'B'|'b'        -> bin 
    char hex;
    size_t val_sz;
    char *val;
 
    char (*obj_input) (FILE *);
    char (*obj_print) (FILE *);
    struct c_str_int* (*obj_dup) (struct c_str_int *);
    char (*obj_del) (struct c_str_int *);
    struct c_str_int* (*hex_conv) (char, char);
    struct c_str_int* (*num_plus) (struct c_str_int *);
    struct c_str_int* (*num_mul) (struct c_str_int *);
    struct c_str_int* (*num_div) (struct c_str_int *);
    struct c_str_int* (*num_mod) (struct c_str_int *);
    struct c_str_int* (*num_exp) (struct c_str_int *);

} __attribute__((packed, aligned(4))) c_str_int;

typedef struct c_str_ieee754_float{
    // 0 -> 32
    // 1 -> 64
    char     float_mod;
    long long int float_bit; 
    size_t int_val_sz;
    size_t dec_val_sz;
    char* integer_val;
    char* decimal_val;

    struct c_str_ieee754_float* (*ceil) (struct c_str_ieee754_float *);
    struct c_str_ieee754_float* (*floor) (struct c_str_ieee754_float *);

} c_str_ieee754_float;



#ifdef COMPILE_TEST

void test_c_str_int_aligned();
void test_c_str_int_initial();

#endif 

#endif 