#include <sys/syscall.h>
#include <unistd.h>
#include <stdint.h>

int main(int argc, char *argv[]){

    syscall(SYS_write, 1, "Hello, pure!\n", 13);

    return 0;
}