#include <stdio.h>
int count1=0,count2=1, k;

void merge(int arr[], int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    int tmp[r - p + 1];
    
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) tmp[t++] = arr[i++];
        else tmp[t++] = arr[j++];
    }
    while (i <= q) tmp[t++] = arr[i++];
    while (j <= r) tmp[t++] = arr[j++];
    
    for (i = p, t = 0; i <= r; i++, t++){
        arr[i] = tmp[t];
        if(++count1==k){
            printf("%d",tmp[t]);
            count2--;
        }
    }
}

void merge_sort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main(void) {
    int n;
    scanf("%d %d",&n, &k);
    int arr[n];
    for (int i = 0; i <n; i++) scanf("%d", &arr[i]);
    merge_sort(arr, 0, n-1);
    if(count2) printf("-1\n");
    return 0;
}
