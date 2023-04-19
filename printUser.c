#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    uid_t uid;

    uid = getuid();

    printf("El ID del usuario que ejecuto el procesos es: %d\n", uid);

    return 0;
}