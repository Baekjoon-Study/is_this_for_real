#include <stdio.h>
int isStar(int n,int i,int j){if(i%3==1&&j%3==1)return printf(" ");while(n>3){if(i/(n/2)%2==1&&j%n>(i%(n/2))*2)return printf(" ");n/=2;}return printf("*");}
int main(void){int n;scanf("%d",&n);for (int i=1;i<=n;i++){for(int j=0;j<n-i;j++) printf(" ");for(int j=0;j<n+i-1;j++)j<i+i-1?isStar(n,i-1,j):printf(" ");printf("\n");}}