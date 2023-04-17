int funcf(int n){
    int ret = 0;
    if(n > 10)
        ret = 2*n;
    else 
        ret = 2+n;
    return ret;
}

int funcff(int n){
    return n > 10 ? (n << 1) : (n + 2);
}

int main(void){
    
    return 0;
}