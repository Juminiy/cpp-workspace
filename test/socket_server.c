#include <linux/net.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    syscall(SYS_socket, SYS_SOCKET, argc);

    return 0;
}