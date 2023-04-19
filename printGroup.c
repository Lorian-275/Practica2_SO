#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid, pgid;

    pid = getpid();

    pgid = getpgid(pid);

    printf("El ID del grupo de procesos es: %d\n", pgid);

    return 0;
}