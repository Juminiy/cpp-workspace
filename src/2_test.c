#include "2.h"
#include <stddef.h>
#include <assert.h>
#include <regex.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#ifdef COMPILE_TEST


void test_ull_to_c_str(){
    char *buf_num = ull_to_c_str(rev64(0XACEF0369BD124578));
    int buf_sz __attribute__((unused)) = write(SYS_write, buf_num, 19);
    int end_sz __attribute__((unused)) = write(SYS_write, "\n", 1);
    free(buf_num);
}

void test_int64_dec_to_c_str(){
    // assert to stop 
    // printf("%s\n", int64_dec_to_c_str(0XFF00FF00FFFF00FF));
    // run normal
    printf("%s\n", int64_dec_to_c_str(1237896057));
}

void test_bit32_to_c_str(){
    printf("%s\n", bit32_to_c_str_bin(0b10101));
    printf("%s\n", bit32_to_c_str_bin(0xf0f0f));
}

void test_c_str_bin32_to_int(){
    printf("%08X\n", c_str_bin32_to_int("0b00000000000011110000111100001111"));
    printf("%08X\n", c_str_bin32_to_int("0b00000000000000000000000000010101"));
}

void test_format_c_str_bin32(){ 
    char *_str = "0b0";
    char * _new_str = format_c_str_bin32(_str);
    printf("%s\n", _new_str);
    free(_new_str);
}

void test_format_c_str_int32(){
    printf("%34s\n%s\n", "0b101101", format_c_str_bin32("0b101101"));
    puts("----------------------------------");
    printf("%13s\n%s\n", "0o123456", format_c_str_oct32("0o123456"));
    puts("----------------------------------");
    printf("%10s\n%s\n", "0xf0f0ff", format_c_str_hex32("0xf0f0ff"));
    puts("----------------------------------");
}

void test_c_str_int32_set_head(){
    puts(c_str_bin_set_head(format_c_str_bin32("01010111")));
}

static inline long int 
make_rand_int32()
{
    return rand() % (SLONG_INT_MAX) ;
}


void test_c_str_dec_plus(){

    long int _dest, _src;
    char *_dest_c_str, *_src_c_str;


    // + +
    _dest = make_rand_int32(), _src = make_rand_int32();
    _dest_c_str = int64_dec_to_c_str(_dest), _src_c_str = int64_dec_to_c_str(_src);
    printf("%s, %s\n", _dest_c_str, _src_c_str);
    printf("%ld\n%s\n--------------------\n", _dest + _src, c_str_dec_plus(_dest_c_str, _src_c_str));
    free(_dest_c_str), free(_src_c_str);

    // + - 
    _dest = make_rand_int32(), _src = make_rand_int32();
    _dest_c_str = int64_dec_to_c_str(_dest), _src_c_str = int64_dec_to_c_str(_src);
    printf("%s, -%s\n", _dest_c_str, _src_c_str);
    printf("%ld\n%s\n--------------------\n", _dest - _src, c_str_dec_plus(_dest_c_str, c_str_dec_sign_flip(_src_c_str)));
    free(_dest_c_str), free(_src_c_str);

    // - + 
    _dest = make_rand_int32(), _src = make_rand_int32();
    _dest_c_str = int64_dec_to_c_str(_dest), _src_c_str = int64_dec_to_c_str(_src);
    printf("-%s, %s\n", _dest_c_str, _src_c_str);
    printf("%ld\n%s\n--------------------\n", -_dest + _src, c_str_dec_plus(c_str_dec_sign_flip(_dest_c_str), _src_c_str));
    free(_dest_c_str), free(_src_c_str);

    // - -
    _dest = make_rand_int32(), _src = make_rand_int32();
    _dest_c_str = int64_dec_to_c_str(_dest), _src_c_str = int64_dec_to_c_str(_src);
    printf("-%s, -%s\n", _dest_c_str, _src_c_str);
    printf("%ld\n%s\n--------------------\n", -_dest -_src, c_str_dec_plus(c_str_dec_sign_flip(_dest_c_str), c_str_dec_sign_flip(_src_c_str)));
    free(_dest_c_str), free(_src_c_str);


    // val val
    _src = make_rand_int32();
    _src_c_str = int64_dec_to_c_str(_src);
    printf("%s, %s\n", _src_c_str, _src_c_str);
    printf("%ld\n%s\n--------------------\n", _src + _src, c_str_dec_plus(_src_c_str, _src_c_str));
    free(_src_c_str);

    // val -val
    _src = make_rand_int32();
    _src_c_str = int64_dec_to_c_str(_src);
    printf("%s, -%s\n", _src_c_str, _src_c_str);
    printf("%ld\n%s\n--------------------\n", _src - _src, c_str_dec_plus(_src_c_str, c_str_dec_sign_flip(_src_c_str)));
    free(_src_c_str);

    // -val val
    _src = make_rand_int32();
    _src_c_str = int64_dec_to_c_str(_src);
    printf("-%s, %s\n", _src_c_str, _src_c_str);
    printf("%ld\n%s\n--------------------\n",- _src + _src, c_str_dec_plus( c_str_dec_sign_flip(_src_c_str), _src_c_str));
    free(_src_c_str);

    // -val -val
    _src = make_rand_int32();
    _src_c_str = int64_dec_to_c_str(_src);
    printf("-%s, -%s\n", _src_c_str, _src_c_str);
    printf("%ld\n%s\n--------------------\n", -_src - _src, c_str_dec_plus( c_str_dec_sign_flip(_src_c_str),  c_str_dec_sign_flip(_src_c_str)));
    free(_src_c_str);

    // 0 0 
    printf("0, 0\n");
    printf("%d\n%s\n--------------------\n", 0, c_str_dec_plus("0", "0"));
    
}

void test_c_str_dec_plus_n_round(int _n){
    for(int i = 0; i < _n; i ++){
        printf("Test Round %d --------------------\n",i + 1);
        test_c_str_dec_plus();
    }
}

void test_c_str_dec_comp(){
    printf("%d = 0\n", c_str_dec_comp("55", "55"));
    printf("%d = 3\n", c_str_dec_comp("55", "-55"));
    printf("%d = 2\n", c_str_dec_comp("55", "-67"));
    printf("%d = 2\n", c_str_dec_comp("55", "-777"));
    printf("%d = 2\n", c_str_dec_comp("55", "-5"));
    printf("%d = 2\n", c_str_dec_comp("55", "5"));
    printf("%d = 1\n", c_str_dec_comp("55", "67"));
    printf("%d = 1\n", c_str_dec_comp("55", "5777"));
    printf("%d = 2\n", c_str_dec_comp("55", "0"));
    printf("comp(0, -0) = %d\n", c_str_dec_comp("0", "-0"));
    printf("comp(0, 0) = %d\n", c_str_dec_comp("0", "0"));
    printf("comp(90897, 90897) = %d\n", c_str_dec_comp("90897", "90897"));
    printf("comp(-90789, -90789) = %d\n", c_str_dec_comp("-90789", "-90789"));
    printf("comp(5, -5) = %d\n", c_str_dec_comp("5", "-5"));
    printf("comp(-15, 5) = %d\n", c_str_dec_comp("-15", "5"));
    printf("comp(123456, 555) = %d\n", c_str_dec_comp("123456", "555"));
    printf("comp (-65222, -35321) = %d\n", c_str_dec_comp("-65222", "-35321"));
    printf("comp(-652222222, -353299999999991) = %d\n", c_str_dec_comp("-652222222", "-353299999999991"));
    printf("comp(652222222866, 413423434141353299999999991) = %d\n", c_str_dec_comp("652222222866", "413423434141353299999999991"));
}


#endif 