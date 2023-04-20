// @date     2023.04.06
// @author   chisato
// @test_url https://www.luogu.com.cn/problem/P1601

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

static inline char* 
c_str_dec_zero()
{
    char *dec_zero = (char *)(malloc(2));
    assert(dec_zero);
    dec_zero[0] = '0', dec_zero[1] = '\0';
    return dec_zero;
}

static inline char*
c_str_dec_rm_lead_zero(char *_dec)
{
    char *_dec_p = _dec;
    while(_dec_p && *_dec_p == '0'){
        _dec_p ++;
    }
    return ((_dec_p == NULL || strlen(_dec_p) == 0) ? 
            c_str_dec_zero() : _dec_p
    );
}

static inline int max_int32(int _dest, int _src){
    return _dest > _src ? _dest : _src;
}

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

    while(_dest_l >= 0 && _src_l >= 0){
        ans[ans_l] = _dest[_dest_l] + _src[_src_l] - 96 + bit_c;
        bit_c = ans[ans_l] >= 10 ? 1 : 0;
        ans[ans_l] = (ans[ans_l] >= 10 ? ans[ans_l] + 38 : ans[ans_l] + 48);
        --_dest_l, --_src_l, --ans_l; 
    }


    #ifdef RUNTIME_DEBUG
    printf("dest_l = %d, src_l = %d, ans_l = %d\n", _dest_l, _src_l, ans_l);
    #endif 

    while(_dest_l >= 0){
        ans[ans_l] = _dest[_dest_l] - 48 + bit_c;
        bit_c = ans[ans_l] >= 10 ? 1 : 0;
        ans[ans_l] = (ans[ans_l] >= 10 ? ans[ans_l] + 38 : ans[ans_l] + 48);
        --_dest_l, --ans_l; 
    }

    while(_src_l >= 0){
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
int main(int argc, char *args[]){

    char _s1[502], _s2[502];
    scanf("%s%s",_s1, _s2);
    printf("%s", c_str_dec_bit_plus(_s1, _s2));

    return 0;
}