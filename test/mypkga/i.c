#include <sys/syscall.h>
#include <unistd.h>
int main(void){
    write(SYS_write, "你好,世界\n", 14);
    return 0;
}