#include <stdio.h>
#include <math.h>
int cantor(int n){
    n%3==1? printf(" "): n? cantor(n/3): printf("-");
    return 0;
}
int main(void) {
    int n;
    while(scanf("%d",&n)!= EOF){
        for(int i=0; i<pow(3,n); i++) cantor(i);
        printf("\n");
    }
}