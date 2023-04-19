#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid, sid;

    pid = getpid();

    sid = getsid(pid);

    printf("El ID de la sesion es: %d\n", sid);

    return 0;
}