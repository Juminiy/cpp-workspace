#include "2.h"
#include "3.h"
#include <string.h>
#include <stdlib.h>


/// @brief make (2|8|10|16) hex unlimited length integer
/// @param hex 
/// @param val 
/// @return c_str_int ptr allocated in heap
c_str_int* makeInt(char hex, const char *val){
    c_str_int *dest = (c_str_int*)malloc(sizeof(c_str_int));
    switch (hex)
    {
    case 2:{
        dest->hex = INT32_BIN;
    }
        break;
    case 8:{
        dest->hex = INT32_OCT;
    }
        break;
    case 10:{
        dest->hex = INT32_DEC;
    }
        break;
    case 16:{
        dest->hex = INT32_HEX;
    }
        break;
    default:{
        // error
    }
        break;
    }
    dest->val_sz = strlen(val);
    dest->val = strdup(val);
    return dest;
}

/// @brief convert c_str_int to decimal format
/// @param src 
/// @return 
c_str_int* conv2Dec(c_str_int* src){
    return PTR_UNDEFINE_VALUE;
}

c_str_int* conv2Hex(c_str_int* src){
    return PTR_UNDEFINE_VALUE;
}

c_str_int* conv2Bin(c_str_int* src){
    return PTR_UNDEFINE_VALUE;
}

c_str_int* conv2Oct(c_str_int* src){
    return PTR_UNDEFINE_VALUE;
}

c_str_int* objDup(c_str_int* src){
    return makeInt(src->hex, src->val);
}

char objDel(c_str_int *src){
    return BYTE_UNDEFINE_VALUE;
}