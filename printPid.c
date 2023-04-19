#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;

    pid = getpid();

    printf("El ID del proceso actual es: %d\n", pid);

    return 0;
}