#include <sys/syscall.h>
#include <unistd.h>

int main(int argc, char **argv){

    write(SYS_write, "Hello, Arm MacOS!\n", 18);

    return 0;
}