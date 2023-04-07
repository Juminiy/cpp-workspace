#include <unistd.h>
#include <stddef.h>
#include <sys/syscall.h>
#include <stdlib.h>

int main(void){
    char *buf = (char *)(malloc(20));
    syscall(SYS_read, buf, 20);
    syscall(SYS_write, buf, 20);
    free(buf);
    return 0;
}