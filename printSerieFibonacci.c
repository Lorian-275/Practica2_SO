#include<stdio.h>

int main(){
    int n, i;
    int t1=0, t2=1,sig;

    printf("Ingrese el numero de elementos de la serie: ");
    scanf("%d", &n);

    for ( i = 0; i <= n; i++)
    {
        if(i==n){
            printf("%d\n",t1);
        }
        sig = t1 + t2;
        t1 = t2;
        t2 = sig;
    }
    return 0;
}