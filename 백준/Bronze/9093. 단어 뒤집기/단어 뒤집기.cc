#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        char str[1001];
        fgets(str,1001,stdin);
        int start_word = -1;
        int end_word = 0;
        for (int j=0; j<strlen(str); j++){
            if(str[j]==' ' || str[j]=='\n'){
                for(int t=end_word-1; t>start_word; t--) printf("%c",str[t]);
                printf(" ");
                start_word = end_word;
            }
            end_word++;
        }
        printf("\n");
    }
    return 0;
}