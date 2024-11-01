#include <stdio.h>
#include <math.h>

void hanoi(int n, char from, char tmp, char to){
    if (n==1) printf("%c %c\n",from,to);
    else{
        hanoi((n-1),from,to,tmp);
        printf("%c %c\n",from,to);
        hanoi((n-1),tmp,from,to);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int k = pow(2,n)-1;
    printf("%d\n",k);
    hanoi(n,'1','2','3');   
}