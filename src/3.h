#include <stddef.h>

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
    char prefix;
    char format;
    size_t val_sz;
    char *val;
} __attribute__((packed, aligned(8))) c_str_int;



#ifdef COMPILE_TEST

void test_c_str_int_aligned();

#endif 