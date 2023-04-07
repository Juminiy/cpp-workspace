#ifndef _2_H
#define _2_H

#define INDEX_INITIAL_VALUE 0
#define INDEX_BORDER_VALUE 0

#define BYTE_INITIAL_VALUE 0 
#define BYTE_UNDEFINE_VALUE 0

#define PTR_INITIAL_VALUE NULL
#define PTR_UNDEFINE_VALUE NULL

#define LONG_LONG_INT_BITS 64
#define LONG_LONG_INT_BYTES 8
#define LONG_INT_BITS 32
#define LONG_INT_BYTES 4
#define X64_INT_BITS 32
#define X64_INT_BYTES 4

#define INT_32_HEAD_BITS  2 
#define INT_BIN_HEAD_BITS INT_32_HEAD_BITS
#define INT_OCT_HEAD_BITS INT_32_HEAD_BITS 
#define INT_DEC_HEAD_BITS INT_32_HEAD_BITS
#define INT_HEX_HEAD_BITS INT_32_HEAD_BITS

#define X64_INT_BIN_BITS X64_INT_BITS
#define X64_INT_OCT_BITS 11
#define X64_INT_UDEC_MAX_BITS 10
#define X64_INT_HEX_BITS 8

#define X64_LONG_LONG_BIN_BITS LONG_LONG_INT_BITS 

#define X64_LONG_LONG_UDEC_MAX_BITS 19
/**
 * (1 << 31) - 1 = 2147483647
 * (1 << 32) - 1 = 4294967295
 * (1 << 63) - 1 = 9223372036854775807
 * (1 << 64) - 1 = 18446744073709551615
 */

// dec                4294967295
#define ULONG_INT_MAX 0XFFFFFFFF
#define ULONG_INT_MIN 0X00000000
#define SLONG_INT_MAX 0X7FFFFFFF
#define SLONG_INT_MIN 0X80000000
// dec                     18446744073709551615
#define ULONG_LONG_INT_MAX 0XFFFFFFFFFFFFFFFF
#define ILONG_LONG_INT_MIN 0X0000000000000000
#define SLONG_LONG_INT_MAX 0X7FFFFFFFFFFFFFFF
#define SLONG_LONG_INT_MIN 0X8000000000000000

#define INT64_LOW32_MASK  0X00000000FFFFFFFF
#define INT64_HIGH32_MASK 0XFFFFFFFF00000000

enum int32_sys{
    FILL_0, FILL_1, FILL_2, FILL_3, FILL_4, FILL_5, FILL_6, FILL_7, FILL_8, 
    FILL_9, FILL_10, FILL_11, FILL_12, FILL_13, FILL_14, FILL_15, FILL_16, 
    FILL_17, FILL_18, FILL_19, FILL_20, FILL_21, FILL_22, FILL_23, FILL_24, 
    FILL_25, FILL_26, FILL_27, FILL_28, FILL_29, FILL_30, FILL_31, FILL_32, 
    FILL_33, FILL_34, FILL_35, FILL_36, FILL_37, FILL_38, FILL_39, FILL_40, 
    FILL_41, FILL_42, FILL_43, FILL_44, FILL_45, FILL_46, FILL_47, FILL_48, 
    FILL_49, FILL_50, FILL_51, FILL_52, FILL_53, FILL_54, FILL_55, FILL_56, 
    FILL_57, FILL_58, FILL_59, FILL_60, FILL_61, FILL_62, FILL_63, FILL_64, 
    FILL_65, FILL_66, FILL_67, FILL_68, FILL_69, FILL_70, FILL_71, FILL_72, 
    FILL_73, FILL_74, FILL_75, FILL_76, FILL_77, FILL_78, FILL_79, FILL_80, 
    FILL_81, FILL_82, FILL_83, FILL_84, FILL_85, FILL_86, FILL_87, FILL_88, 
    FILL_89, FILL_90, FILL_91, FILL_92, FILL_93, FILL_94, FILL_95, FILL_96, 
    FILL_97, INT32_BIN, FILL_99, INT32_DEC, FILL_101, FILL_102, FILL_103, FILL_104, 
    FILL_105, FILL_106, FILL_107, FILL_108, FILL_109, FILL_110, INT32_OCT, FILL_112, 
    FILL_113, FILL_114, FILL_115, FILL_116, FILL_117, FILL_118, FILL_119, INT32_HEX
};

#define POSITIVE_TAG 0
#define NEGATIVE_TAG 1

#define PLUS_TAG  0
#define MINUS_TAG 1

#define FLOAT32_SIGN_MASK   0X80000000
#define FLOAT32_OFFSET_MASK 0X7F800000
#define FLOAT32_NUM_MASK    0X007FFFFF

#define FLOAT32_STD_DEVIATION 127
#define FLOAT64_STD_DEVIATION 1023

#define FLOAT_HIDDEN_BIT 1
#define FLOAT32_NUM_BITS 23
#define FLOAT64_NUM_BITS 64

// + (2^128 - 2^104)
#define FLOAT32_POSITIVE_MAX_BITS 0X7FFFFFFF
// + (2^(-126))
#define FLOAT32_POSITIVE_MIN_BITS 0X00000000
// - (2^(-126))
#define FLOAT32_NEGATIVE_MAX_BITS 0X80000000
// - (2^128 - 2^104)
#define FLOAT32_NEGATIVE_MIN_BITS 0XFFFFFFFF


unsigned long long int rev64(unsigned long long int _bits);
char* ull_to_c_str(unsigned long long int _bits);
char* bit64_to_c_str_hex64(long long int _bits);
char* bit32_to_c_str_hex32(long int _bits);


char* format_c_str_bin32(const char *);
char* format_c_str_oct32(const char *);
// @deprecated
char* format_c_str_udec32(const char *);
char* format_c_str_hex32(const char *);

char* c_str_bin_get_val(const char *);
char* c_str_oct_get_val(const char *);
char* c_str_dec_get_val(const char *);
char* c_str_hex_get_val(const char *);

char* c_str_bin_set_head(const char *);
char* c_str_oct_set_head(const char *);
char* c_str_dec_set_head(const char *);
char* c_str_hex_set_head(const char *);


char* c_str_bin_to_c_str_oct(const char *);
char* c_str_oct_to_c_str_bin(const char *);
char* c_str_bin_to_c_str_hex(const char *);
char* c_str_hex_to_c_str_bin(const char *);
char* c_str_bin_to_c_str_dec(const char *);
char* c_str_dec_to_c_str_bin(const char *);


int float32_c_str_to_bit32(const char *);
char* bit32_to_c_str_bin(int );
int c_str_bin32_to_int(const char *);
float bit32_to_float32(int );

char* ieee754_float32_ceil(const char *);
char* ieee754_float32_floor(const char *);
char* ieee754_float32_accuracy_prev(const char *);
char* ieee754_float32_accuracy_next(const char *);


enum comp_stat{
    COMP_EQ, COMP_LS, COMP_GT, COMP_RV
};  


char* c_str_dec_plus(const char *, const char *);
char* c_str_dec_mul(const char *, const char *);
char* c_str_dec_div(const char *, const char *);


#ifdef COMPILE_TEST
void test_c_str_dec_comp();
void test_ull_to_c_str();
void test_bit32_to_c_str();
void test_c_str_bin32_to_int();
void test_format_c_str_bin32();
void test_format_c_str_int32();
void test_c_str_int32_set_head();
void test_static_inline_c_str_dec_rm_zero();
void test_static_inline_c_str_dec_bit_plus();
void test_c_str_bin_mv_bit();
void test_c_str_dec_bit_minus();
void test_c_str_dec_plus();
void test_c_str_dec_plus_n_round(int );
void test_make_rand();
void test_int64_dec_to_c_str();
#endif 

#endif 