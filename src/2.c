#include "2.h"
#include <malloc.h>
#include <assert.h>
#include <regex.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>


// Pass 
unsigned long long int rev64(unsigned long long int int64_num){
    return ((int64_num & INT64_LOW32_MASK) << LONG_INT_BITS) + 
            ((int64_num & INT64_HIGH32_MASK) >> LONG_INT_BITS);
}

static inline char 
bin_to_char(char bin_num)
{
    assert(bin_num == 0 || bin_num == 1);
    return bin_num + 48;
}
static inline char 
oct_to_char(char oct_num)
{
    assert(oct_num >= 0 && oct_num <= 7);
    return oct_num + 48;
}
static inline char 
dec_to_char(char dec_num)
{
    assert(dec_num >= 0 && dec_num <= 9);
    return dec_num + 48;
}

static inline char 
hex_to_char_v0(char hex_num)
{
    assert(hex_num >= 0 && hex_num <= 15);
    return (hex_num >= 0 && hex_num <= 9) ? hex_num + 48 : hex_num + 87;
}

// Pass 
// 0 -> '0' ... 9 -> '9' 
// 10 -> 'A' ... 15 -> 'F'
static inline char 
hex_to_char(char hex_num)
{
    assert(hex_num >= 0 && hex_num <= 15);
    return (hex_num >= 0 && hex_num <= 9) ? hex_num + 48 : hex_num + 55;
}

// Pass
// 0B 1010 1110 1011 0111 0101 1000 0001 1111
// 0X  A    E    B    7    5    8     1    F

/// @brief 
/// @param int64_num 
/// @return 0X[0-9A-F]{16} 
char* ull_to_c_str(unsigned long long int int64_num){
    char *num_buf = (char *)(malloc(INT_HEX_HEAD_BITS + (LONG_LONG_INT_BYTES << 1) + 1));
    assert(num_buf);
    num_buf[0]  = '0', num_buf[1] = 'X';
    num_buf[17]  = hex_to_char((char)((int64_num & 0X000000000000000F) >> 0));
    num_buf[16]  = hex_to_char((char)((int64_num & 0X00000000000000F0) >> 4));
    num_buf[15]  = hex_to_char((char)((int64_num & 0X0000000000000F00) >> 8));
    num_buf[14]  = hex_to_char((char)((int64_num & 0X000000000000F000) >> 12));
    num_buf[13]  = hex_to_char((char)((int64_num & 0X00000000000F0000) >> 16));
    num_buf[12]  = hex_to_char((char)((int64_num & 0X0000000000F00000) >> 20));
    num_buf[11]  = hex_to_char((char)((int64_num & 0X000000000F000000) >> 24));
    num_buf[10]  = hex_to_char((char)((int64_num & 0X00000000F0000000) >> 28));
    num_buf[9]   = hex_to_char((char)((int64_num & 0X0000000F00000000) >> 32));
    num_buf[8]   = hex_to_char((char)((int64_num & 0X000000F000000000) >> 36));
    num_buf[7]   = hex_to_char((char)((int64_num & 0X00000F0000000000) >> 40));
    num_buf[6]   = hex_to_char((char)((int64_num & 0X0000F00000000000) >> 44));
    num_buf[5]   = hex_to_char((char)((int64_num & 0X000F000000000000) >> 48));
    num_buf[4]   = hex_to_char((char)((int64_num & 0X00F0000000000000) >> 52));
    num_buf[3]   = hex_to_char((char)((int64_num & 0X0F00000000000000) >> 56));
    num_buf[2]   = hex_to_char((char)((int64_num & 0XF000000000000000) >> 60));
    num_buf[18]  = '\0';
    return num_buf;
}
char* bit64_to_c_str_hex64(long long int _bits){
    return ull_to_c_str(_bits);
}

#ifdef COMPILE_TEST
void test_ull_to_c_str(){
    char *buf_num = ull_to_c_str(rev64(0XACEF0369BD124578));
    int buf_sz = write(SYS_write, buf_num, 19);
    int end_sz = write(SYS_write, "\n", 1);
    free(buf_num);
}
#endif 

/// @brief 
/// @param _bits 
/// @return 0X[0-9A-F]{8}
char* bit32_to_c_str_hex32(long int _bits){
    char * hex32_dest = (char*)(malloc(X64_INT_HEX_BITS + 1));
    hex32_dest[X64_INT_HEX_BITS] = '\0';

    return PTR_UNDEFINE_VALUE;
}


// binary type system
// 0b 0B bin binary
// 0o 0O oct octal
// 0d 0D dec decimal
// 0x 0X hex hexadecimal

// 2 < - > 8
// 2 < - > 16
// 2 < - > 10 

// 0xf0f0f -> "0b00000000000011110000111100001111"
// 0b10101 -> "0b00000000000000000000000000010101"
/// @brief 
/// @param _bits 
/// @return 0b[01]{32} 
char* bit32_to_c_str_bin(int _bits){
    char *bits = (char*)(malloc(INT_BIN_HEAD_BITS + X64_INT_BIN_BITS + 1));
    assert(bits);
    memset(bits, '0', INT_BIN_HEAD_BITS + X64_INT_BIN_BITS); 
    bits[1] = 'b';
    for(int i = X64_INT_BIN_BITS - 1; i >= INDEX_BORDER_VALUE; -- i){ 
        if(_bits & (1 << i))
            bits[X64_INT_BIN_BITS - i + 1] = '1';
    }
    bits[INT_BIN_HEAD_BITS + X64_INT_BIN_BITS] = '\0';
    return bits;
}
#ifdef COMPILE_TEST
void test_bit32_to_c_str(){
    printf("%s\n", bit32_to_c_str_bin(0b10101));
    printf("%s\n", bit32_to_c_str_bin(0xf0f0f));
}
#endif 


// 0xf0f0f <- "0b00000000000011110000111100001111"
// 0b10101 <- "0b00000000000000000000000000010101"
/// @brief 
/// @param bits 0b[01]{32} 
/// @return  
int c_str_bin32_to_int(const char *bits){
    int _bits = 0;
    for(int i = INT_BIN_HEAD_BITS; i < X64_INT_BIN_BITS + INT_BIN_HEAD_BITS; ++ i){
        if(bits[i] == '1')
            _bits |= (1 << (X64_INT_BIN_BITS + INT_BIN_HEAD_BITS - i - 1));
    }
    return _bits;
}
#ifdef COMPILE_TEST
void test_c_str_bin32_to_int(){
    printf("%08X\n", c_str_bin32_to_int("0b00000000000011110000111100001111"));
    printf("%08X\n", c_str_bin32_to_int("0b00000000000000000000000000010101"));
}
#endif 

// @abstraction 
static inline char* 
format_c_str_int32(char _type, const char *_src, int head_bits, int type_bits)
{   
    int tot_bits = head_bits + type_bits;
    char *_dest = (char*) malloc(tot_bits + 1);
    assert(_dest);
    _dest[tot_bits] = '\0';
    int _src_l = strlen(_src) - head_bits;
    memset(_dest, '0', tot_bits);
    _dest[1] = _type;

    memcpy(_dest + tot_bits - _src_l, _src + head_bits, _src_l);

    return _dest;
}

// "0b101101" -> "0b00000000000000000000000000101101"
/// @brief calculate from end bit
/// @param _bin 0b[0-1]{1,32}
/// @return 0b[0-1]{32}
char* format_c_str_bin32(const char *_bin){
    return format_c_str_int32(INT32_BIN, _bin, INT_BIN_HEAD_BITS, X64_INT_BIN_BITS);
}
#ifdef COMPILE_TEST 
void test_format_c_str_bin32(){ 
    char *_str = "0b0";
    char * _new_str = format_c_str_bin32(_str);
    printf("%s\n", _new_str);
    free(_new_str);
}
#endif 


// "0o35430123" -> "0o00035430123"
/// @brief 
/// @param _oct 0o[0-7]{1,11}
/// @return 0o[0-7]{11}
char* format_c_str_oct32(const char *_oct){
    return format_c_str_int32(INT32_OCT, _oct, INT_OCT_HEAD_BITS, X64_INT_OCT_BITS);
}

// @deprecated
// regex [0-9]{1,10} -> [0-9]{10} 
char* format_c_str_udec32(const char *_dec){
    return format_c_str_int32(INT32_DEC, _dec, INT_DEC_HEAD_BITS, X64_INT_UDEC_MAX_BITS);
}

/// @brief 
/// @param _hex 0x[0-9a-f]{1,8} 
/// @return 0x[0-9a-f]{8}
char* format_c_str_hex32(const char *_hex){ 
    return format_c_str_int32(INT32_HEX, _hex, INT_HEX_HEAD_BITS, X64_INT_HEX_BITS);
}
#ifdef COMPILE_TEST
void test_format_c_str_int32(){
    printf("%34s\n%s\n", "0b101101", format_c_str_bin32("0b101101"));
    puts("----------------------------------");
    printf("%13s\n%s\n", "0o123456", format_c_str_oct32("0o123456"));
    puts("----------------------------------");
    printf("%10s\n%s\n", "0xf0f0ff", format_c_str_hex32("0xf0f0ff"));
    puts("----------------------------------");
}
#endif 


char* c_str_bin_get_val(const char *_bin){
    return _bin + INT_BIN_HEAD_BITS;
}
char* c_str_oct_get_val(const char *_oct){
    return _oct + INT_OCT_HEAD_BITS;
}
char* c_str_dec_get_val(const char *_dec){
    return _dec + INT_DEC_HEAD_BITS;
}
char* c_str_hex_get_val(const char *_hex){
    return _hex + INT_HEX_HEAD_BITS;
}


// @abstraction
/// @brief 
/// @param _type 
/// @param _src 
/// @param head_bits 
/// @param type_bits 
/// @return 
/// @warning
/// @bug buffer overflow detected ***: terminated 
///     core-dump
static inline char*
c_str_int32_set_head(int _type, const char * _src, int head_bits, int type_bits)
{
    int tot_bits = head_bits + type_bits;
    // warning line 
    char *_dest = (char*)(malloc(tot_bits + 1));
    assert(_dest);
    _dest[0] = '0', _dest[1] = _type, _dest[tot_bits] = '\0';
    memcpy(_dest + head_bits, _src, tot_bits);
    return _dest;
}


char* c_str_bin_set_head(const char *_bin){
    return c_str_int32_set_head(INT32_BIN, _bin, INT_BIN_HEAD_BITS, X64_INT_BIN_BITS);
}
char* c_str_oct_set_head(const char *_oct){
    return c_str_int32_set_head(INT32_OCT, _oct, INT_OCT_HEAD_BITS, X64_INT_OCT_BITS);
}
char* c_str_dec_set_head(const char *_dec){
    return c_str_int32_set_head(INT32_DEC, _dec, INT_DEC_HEAD_BITS, X64_INT_UDEC_MAX_BITS);
}
char* c_str_hex_set_head(const char *_hex){
    return c_str_int32_set_head(INT32_HEX, _hex, INT_HEX_HEAD_BITS, X64_INT_HEX_BITS);
}

#ifdef COMPILE_TEST
void test_c_str_int32_set_head(){
    puts(c_str_bin_set_head(format_c_str_bin32("01010111")));
}
#endif


// calcu from end bit
// 01 110 100 010 011 011 111 000 100 110 101 -> 
//  1  6   4   2   3   3   7   0   4   6   5 
char* c_str_bin_to_c_str_oct(const char *_bin){
    return PTR_UNDEFINE_VALUE;
}

char* c_str_oct_to_c_str_bin(const char *_oct){
    return PTR_UNDEFINE_VALUE;
}

char* c_str_bin_to_c_str_hex(const char *_bin){
    return PTR_UNDEFINE_VALUE;
}

char* c_str_hex_to_c_str_bin(const char *_hex){
    return PTR_UNDEFINE_VALUE;
}

char* c_str_bin_to_c_str_dec(const char *_bin){
    return PTR_UNDEFINE_VALUE;
}

char* c_str_dec_to_c_str_bin(const char *_dec){
    return PTR_UNDEFINE_VALUE;
}



// assume input is accuracy float32
int float32_c_str_to_bit32(const char *dec_num){
    return 0;
}

// version 1
// 0X40A80000 -> 5.25 
// int section over 2^32 - 1 must cast to e 
// assume input is accuracy float32

/// @unfinished 
float bit32_to_float32(int _bits){
    
    char sign = (_bits & FLOAT32_SIGN_MASK) ? NEGATIVE_TAG : POSITIVE_TAG;

    #ifdef RUNTIME_DEBUG
        printf("sign = %d\n", sign);
    #endif 

    char exp = (char) (((_bits & FLOAT32_OFFSET_MASK) >> FLOAT32_NUM_BITS) - (FLOAT32_STD_DEVIATION));
    
    #ifdef RUNTIME_DEBUG
        printf("exp = %d\n", exp);
    #endif 
    
    _bits &= FLOAT32_NUM_MASK;
    
    #ifdef RUNTIME_DEBUG
        printf("num_bits = 0x%x\n", _bits);
    #endif 
    
    int num_int = +FLOAT_HIDDEN_BIT;
    float num_float = +0.0;
    int tmp_mask = 0;
    
    for(int idx = INDEX_BORDER_VALUE; idx < exp; ++ idx){
        num_int <<= 1;
        tmp_mask = (1 << (FLOAT32_NUM_BITS - idx - 1));
        num_int += ((_bits & tmp_mask) ? 1 : 0);
        _bits &= (tmp_mask - 1);
        
        #ifdef RUNTIME_DEBUG
            printf("int_add loop %d, num_int = %d, tmp_mask = 0x%x, num_bits = 0x%x\n", idx, num_int, tmp_mask, _bits);
        #endif 
    }

    float tmp_float = 0.5;
    for(int ridx = FLOAT32_NUM_BITS - exp - 1; ridx >= INDEX_BORDER_VALUE; -- ridx){
        if(_bits & (1 << ridx)){ 
            num_float += tmp_float;
        }
        tmp_float /= 2;
        #ifdef RUNTIME_DEBUG
            printf("float_add loop %d, num_float = %.10f\n", ridx, num_float);
        #endif 
    }
    return (sign == POSITIVE_TAG) ? (num_int*1.0 + num_float) : (-num_int*1.0 - num_float);
}


char* ieee754_float32_ceil(const char *_num){
    return _num;
}

char* ieee754_float32_floor(const char *_num){
    return _num;
}

char* ieee754_float32_accuracy_prev(const char *_num){
    return _num;
}

char* ieee754_float32_accuracy_next(const char *_num){
    return _num;
}

// regex: -?[1-9]\d*
// _src <  0 -> 1
// _src >= 0 -> 0
static inline char c_str_dec_ls_0(const char * _src)
{
    return _src[0] == '-';
}

static inline char c_str_dec_sign(const char *_src)
{
    return c_str_dec_ls_0(_src);
}

// regex: -?[1-9]\d*
static inline char* c_str_dec_abs(const char *_src)
{
    return c_str_dec_ls_0(_src) ? &_src[1] : _src;
}

// -[1-9]\d* -> [1-9]\d*
// [1-9]\d* -> -[1-9]\d*
static inline char *c_str_dec_sign_flip(const char *_src)
{
    char _src_sign = c_str_dec_sign(_src);
    char *_dest = PTR_INITIAL_VALUE;
    if(_src_sign == POSITIVE_TAG){
        int _src_l = strlen(_src);
        _dest = (char *)(malloc(_src_l + 2));
        _dest[0] = '-', _dest[_src_l + 1] = '\0';
        memcpy(_dest + 1, _src, _src_l);
    }
    return _src_sign ? c_str_dec_abs(_src) : _dest;
}

// Pass V1
// Pass V2
// regex: -?[1-9]\d*
// _dest = _src     -> 0
// _dest < _src     -> 1
// _dest > _src     -> 2
// _dest + _src = 0 -> 3
// regular:

static inline char 
c_str_dec_comp(const char *_dest, const char *_src)
{
    // < 0 NEGATIVE_TAG 
    // > 0 POSITIVE_TAG
    char _dest_sign = c_str_dec_ls_0(_dest), _src_sign = c_str_dec_ls_0(_src);
    char *_dest_abs = c_str_dec_abs(_dest), *_src_abs = c_str_dec_abs(_src);
    int _dest_l = strlen(_dest_abs), _src_l = strlen(_src_abs);
    char abs_cmp = BYTE_INITIAL_VALUE;
    if(_dest_l == _src_l){
        int idx = 0;
        while(idx != _dest_l){
            if(_dest_abs[idx] != _src_abs[idx])
                break;
            idx ++;
        }
        abs_cmp = (idx == _dest_l) ? COMP_EQ : 
            ((_dest_abs[idx] < _src_abs[idx]) ? COMP_LS : COMP_GT);
    } else {
        abs_cmp = (_dest_l < _src_l) ? COMP_LS : COMP_GT;
    }

    return (
        (_dest_l == _src_l) ? 
            ( (abs_cmp == COMP_EQ) ? 
                ( (_dest_sign ^ _src_sign) ? 
                    COMP_RV : COMP_EQ ) : 
                    ( (abs_cmp == COMP_LS) ? 
                        ((_src_sign == POSITIVE_TAG) ? COMP_LS: COMP_GT ) : 
                        ((_dest_sign == POSITIVE_TAG) ? COMP_GT : COMP_LS ) 
                    ) 
            ) :
            (
                (abs_cmp == COMP_LS) ? 
                    ((_src_sign == POSITIVE_TAG) ? COMP_LS: COMP_GT ) : 
                    ((_dest_sign == POSITIVE_TAG) ? COMP_GT : COMP_LS ) 
            )                     
    );
}   

static inline char 
c_str_dec_abs_comp(const char *_dest, const char *_src)
{
    return c_str_dec_comp(c_str_dec_abs(_dest), c_str_dec_abs(_src));
}

#ifdef COMPILE_TEST
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

static inline char 
c_str_dec_opt(const char *_dest, const char *_src)
{
    return c_str_dec_ls_0(_dest) ^ c_str_dec_ls_0(_src);
}
#ifdef COMPILE_TEST
void test_c_str_opt(){
    printf("opt(-1, 1) = %d", c_str_dec_opt("-1" ,"1"));
}
#endif 

// -0 != 0
static inline char 
equal_zero(const char *_dec)
{
    char *_dec_p = _dec;
    while(_dec_p){
        if(*_dec_p != '0')
            break;
        _dec_p ++;
    }
    return _dec_p ? 0 : 1;
}
static inline char 
euqal_zero_infer(const char *_dec)
{
    return *_dec == '0' ? 1 : 0;
}

static inline char* 
c_str_dec_zero()
{
    char *dec_zero = (char *)(malloc(2));
    assert(dec_zero);
    dec_zero[0] = '0', dec_zero[1] = '\0';
    return dec_zero;
}

// _off > 0 -> left move abs(_off)  right_bit = 0 
// _off = 0 -> _bin
// _off < 0 -> right move abs(_off) left_bit = 
static inline char* 
c_str_bin_mv_bit(const char *_bin, int _off)
{   
    assert(_bin);
    int _bin_l = strlen(_bin);
    char *_bin_dest = (char*)(malloc(_bin_l + _off));
    _off > 0 ? ( memcpy(_bin_dest, _bin, _bin_l), memset(_bin_dest + _bin_l, '0', _off) ) :
                ( memset(_bin_dest, _bin[0], -_off), memcpy(_bin_dest - _off, _bin, _bin_l));
    return _bin_dest;
}
#ifdef COMPILE_TEST
void test_c_str_bin_mv_bit(){
    puts("01010100000");
    printf("%s\n--------------------\n", c_str_bin_mv_bit("010101", 5));
    puts("111110101");
    printf("%s\n--------------------\n", c_str_bin_mv_bit("110101", -3));
    puts("0000010101");
    printf("%s\n--------------------\n", c_str_bin_mv_bit("010101", -4));
    puts("1101010000000");
    printf("%s\n--------------------\n", c_str_bin_mv_bit("110101", 7));
}
#endif 

static inline char*
c_str_bin_mul_2(const char *_bin)
{
    return c_str_bin_mv_bit(_bin, 1);
}

static inline char*
c_str_dec_mul_2(char *_dec)
{
    char *_bin = c_str_dec_to_c_str_bin(_dec);
    _bin = c_str_bin_mul_2(_bin);
    return c_str_bin_to_c_str_dec(_bin);
}

static inline char*
c_str_dec_rm_lead_zero(const char *_dec)
{
    char *_dec_p = _dec;
    while(_dec_p && *_dec_p == '0'){
        _dec_p ++;
    }
    return ((_dec_p == NULL || strlen(_dec_p) == 0) ? 
            c_str_dec_zero():
            _dec_p
    );
}
#ifdef COMPILE_TEST
void test_static_inline_c_str_dec_rm_zero(){
    printf("%s\n", c_str_dec_rm_lead_zero("00000012345"));
    printf("%s\n", c_str_dec_rm_lead_zero("012345"));
    printf("%s\n", c_str_dec_rm_lead_zero("0012345"));
    printf("%s\n", c_str_dec_rm_lead_zero("12345"));
    printf("%s\n", c_str_dec_rm_lead_zero("0000000"));
    printf("%s\n", c_str_dec_rm_lead_zero("0"));
    printf("%s\n", c_str_dec_rm_lead_zero(""));
    printf("%s\n", c_str_dec_rm_lead_zero(NULL));
}
#endif 

static inline int max_int32(int _dest, int _src){
    return _dest > _src ? _dest : _src;
}

static inline char
c_str_char_bit_opt(const char _dest, const char _src, const char _opt)
{
    return _opt == PLUS_TAG ? _dest + _src : _dest - _src;
}

// -> opt(_dest,_src)
static inline char 
c_str_dec_bit_opt(const char *_dest, const char *_src, const char _opt)
{
    
}
// Pass 
// -> _dest + _src
static inline char* 
c_str_dec_bit_plus(const char *_dest, const char *_src)
{   
    int _dest_l = strlen(_dest), _src_l = strlen(_src); 
    int ans_l = max_int32(_dest_l, _src_l) + 1;
    #ifdef RUNTIME_DEBUG
    printf("dest_l = %d, src_l = %d, ans_l = %d\n", _dest_l, _src_l, ans_l);
    #endif 

    char bit_c = 0;

    char *ans = (char*)(malloc(ans_l + 1));
    assert(ans);
    ans[0] = '0', ans[ans_l] = '\0';
    
    --_dest_l, --_src_l, --ans_l;

    while(_dest_l >= INDEX_BORDER_VALUE && _src_l >= INDEX_BORDER_VALUE){
        ans[ans_l] = _dest[_dest_l] + _src[_src_l] - 96 + bit_c;
        bit_c = ans[ans_l] >= 10 ? 1 : 0;
        ans[ans_l] = (ans[ans_l] >= 10 ? ans[ans_l] + 38 : ans[ans_l] + 48);
        --_dest_l, --_src_l, --ans_l; 
    }


    #ifdef RUNTIME_DEBUG
    printf("dest_l = %d, src_l = %d, ans_l = %d\n", _dest_l, _src_l, ans_l);
    #endif 

    while(_dest_l >= INDEX_BORDER_VALUE){
        ans[ans_l] = _dest[_dest_l] - 48 + bit_c;
        bit_c = ans[ans_l] >= 10 ? 1 : 0;
        ans[ans_l] = (ans[ans_l] >= 10 ? ans[ans_l] + 38 : ans[ans_l] + 48);
        --_dest_l, --ans_l; 
    }

    while(_src_l >= INDEX_BORDER_VALUE){
        ans[ans_l] = _src[_src_l] - 48 + bit_c;
        bit_c = ans[ans_l] >= 10 ? 1 : 0;
        ans[ans_l] = (ans[ans_l] >= 10 ? ans[ans_l] + 38 : ans[ans_l] + 48);
        --_src_l, --ans_l; 
    }
    
    #ifdef RUNTIME_DEBUG
    printf("dest_l = %d, src_l = %d, ans_l = %d\n", _dest_l, _src_l, ans_l);
    #endif 

    ans[ans_l] += bit_c;
    
    #ifdef RUNTIME_DEBUG
    printf("dest_l = %d, src_l = %d, ans_l = %d\n", _dest_l, _src_l, ans_l);
    puts(ans);
    #endif 

    return c_str_dec_rm_lead_zero(ans);
}
#ifdef COMPILE_TEST
void test_static_inline_c_str_dec_bit_plus(){
    char _s1[502], _s2[502];
    int _s1_l = 0, _s2_l = 0;
    char ch;
    while( (ch = getchar()) != '\n' ){
        _s1[_s1_l++] = ch;
    }
    _s1[_s1_l] = '\0';
    while( (ch = getchar()) != '\n'){
        _s2[_s2_l++] = ch;
    }
    _s2[_s2_l] = '\0';
    printf("%s\n", c_str_dec_bit_plus(_s1, _s2));
}
#endif 


// _-> _dest - _src
// assure _dest > _src 
static inline char*
c_str_dec_bit_minus(const char *_dest, const char *_src)
{
    int _dest_l = strlen(_dest), _src_l = strlen(_src); 
    int ans_l = max_int32(_dest_l, _src_l);
    char bit_c = 0;

    char *ans = (char*)(malloc(ans_l + 1));
    assert(ans);
    ans[ans_l] = '\0';
    
    --_dest_l, --_src_l, --ans_l;

    char cmp_tmp = BYTE_INITIAL_VALUE;
    while(_dest_l >= INDEX_BORDER_VALUE && _src_l >= INDEX_BORDER_VALUE){
        (cmp_tmp = _dest[_dest_l] - _src[_src_l] - bit_c) < 0 ? 
            (ans[ans_l] = cmp_tmp + 58 , bit_c = 1) :
            (ans[ans_l] = cmp_tmp + 48 , bit_c = 0);
        --_dest_l, --_src_l, --ans_l; 
    }

    while(_dest_l >= INDEX_BORDER_VALUE){
        ((cmp_tmp = (_dest[_dest_l] - bit_c)) < '0') ? 
            (ans[ans_l] = cmp_tmp + 10 , bit_c = 1) :
            (ans[ans_l] = cmp_tmp , bit_c = 0);
        --_dest_l, --ans_l; 
    }

    ans[ans_l] -= bit_c;

    return c_str_dec_rm_lead_zero(ans);
}
#ifdef COMPILE_TEST
void test_c_str_dec_bit_minus(){
    printf("%s\n", c_str_dec_bit_minus("100000", "999"));
    printf("%s\n", c_str_dec_bit_minus("100000", "99999"));
    printf("%s\n", c_str_dec_bit_minus("123456", "78901"));
    printf("%s\n", c_str_dec_bit_minus("111111", "111111"));
    printf("%s\n", c_str_dec_bit_minus("3", "1"));
}
#endif


// regex: -?[1-9]\d*
char* c_str_dec_plus(const char *_dest, const char *_src){ 
    
    char _cmp = c_str_dec_abs_comp(_dest, _src);
    char _opt = c_str_dec_opt(_dest, _src);
    char _dest_sign = c_str_dec_sign(_dest), _src_sign = c_str_dec_sign(_src);
    char *_dest_val = c_str_dec_abs(_dest), *_src_val = c_str_dec_abs(_src);
    char ans_sign = ( ( _opt == PLUS_TAG ) ? 
                        _dest_sign :
                        ( 
                            (_cmp == COMP_EQ ) ? POSITIVE_TAG : 
                            ((_cmp == COMP_LS ) ? _src_sign : _dest_sign)
                        )
                    );
    char *ans_val = ( (_opt == PLUS_TAG) ?
                        ((_cmp == COMP_EQ) ? 
                            c_str_dec_mul_2(_dest_val) :
                            c_str_dec_bit_plus(_dest_val, _src_val)
                        ) :
                        ((_cmp == COMP_EQ) ?
                            c_str_dec_zero():
                            ((_cmp == COMP_LS) ?
                                c_str_dec_bit_minus(_src_val, _dest_val):
                                c_str_dec_bit_minus(_dest_val, _src_val)
                            )
                        )
                    );
    return ans_sign ? c_str_dec_sign_flip(ans_val) : ans_val;
}

// regex: -?[1-9]\d*
// fft algorithm 
char* c_str_dec_mul(const char *_dst, const char *_src){
    return PTR_UNDEFINE_VALUE;
}

// regex: -?[1-9]\d*
char* c_str_dec_div(const char *_dst, const char *_src){
    return PTR_UNDEFINE_VALUE;
}





