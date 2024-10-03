#include <stdio.h>
#include <string.h>
int compare(char w1[], char w2[]){
    int l1 = strlen(w1);
    int l2 = strlen(w2);
    if (l1>l2) return 1;
    if (l1==l2) return strcmp(w1,w2);
    return -1;
}
int partition(char arr[][51], int low, int high){
    char pivot[51]; 
    strcpy(pivot, arr[(low+high)/2]);
    while(low<=high){
        while(compare(pivot,arr[low])>0) low++;
        while(compare(pivot,arr[high])<0) high--;
        if(low<=high){
            if(low<high){
                char temp[51];
                strcpy(temp,arr[low]);
                strcpy(arr[low],arr[high]);
                strcpy(arr[high],temp);
            }
            low++;
            high--;
        }
    }
    return low;
}
void quick_sort(char arr[][51],int low, int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot,high);
    }
}
int unique_string(char arr[][51], int n){
    int unique_num = 1;
    for(int i=1; i<n; i++){
        if(strcmp(arr[i],arr[i-1])){
            strcpy(arr[unique_num], arr[i]);
            unique_num++;
        }
    }
    return unique_num;
}
int main(void){
    int n;
    scanf("%d",&n);
    char arr[n][51];
    for(int i=0; i<n; i++) scanf("%s",arr[i]);
    quick_sort(arr,0,n-1);
    n = unique_string(arr,n);
    for(int i=0; i<n; i++)printf("%s\n",arr[i]);
}