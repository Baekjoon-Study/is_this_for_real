#include <stdio.h>

int isStar(int n, int i, int j){
    while(n){
        if (i/n%3==1 && j/n%3==1){
            return printf(" ");
        }
        n/=3;
    }
    return printf("*");
}


int main(void){
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            i==0 || j==0 ? printf("*"):isStar(n,i,j);
        }
        printf("\n");
    }
}