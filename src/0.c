#include "0.h"
#include <stdio.h>

int comp(int type, void *a, void *b){
    switch (type)
    {
        // unsigned char
    case UCHAR:{

    }break;
        // signed char 
    case CHAR:{

    }break;
        // unsigned short
    case USHORT:{

    }break;
        // signed short 
    case SHORT:{

    }break;
        // unsigned int
    case UINT:{

    }break;
        // signed int
    case INT:{
        int * conv_a = (int *)(a);
        int * conv_b = (int *)(b);
        return *conv_a - *conv_b;
    }break;
        // unsigned long int
    case ULONG:{

    }break;
        // signed long int
    case LONG:{

    }break;
        // unsigned long long int
    case ULONGLONG:{

    }break;
        // signed long long int
    case LONGLONG:{

    }break;
        // float 
    case FLOAT:{
        float * conv_a = (float *)(a);
        float * conv_b = (float *)(b);
        float comp_res = *conv_a - *conv_b;
        return comp_res < ABS_1 || comp_res > -ABS_1;
    }break;
        // double
    case DOUBLE:{

    }break;
        // long double
    case LONGDOUBLE:{

    }break;
        // void
    default:{}
    }
    return 0;
}


char tolower_(char c){
    return (c >= 0x41 && c <= 0x5a) ? c + (((c-0x41)<26U) << 5) : c;
}

