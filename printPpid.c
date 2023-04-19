#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid, ppid;

    pid = getpid();
    ppid = getppid();

    printf("El ID del proceso actual es: %d \n", pid);
    printf("El ID del proceso padre es: %d\n", ppid);

    return 0;
}