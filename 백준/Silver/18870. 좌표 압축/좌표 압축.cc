#include <stdio.h>

typedef struct{
    int x, index, rank;
}Point;

int partition(Point *arr, int low, int high){
    int pivot = arr[(low+high)/2].x;
    while(low<=high){
        while(pivot>arr[low].x)low++;
        while(arr[high].x>pivot)high--;
        if(low<=high){
            Point temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
    return low;
}

void quick_point_sort(Point *arr, int low, int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        quick_point_sort(arr,low,pivot-1);
        quick_point_sort(arr,pivot,high);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    Point arr[n];
    for(int i=0; i<n; i++){ 
        scanf("%d", &arr[i].x);
        arr[i].index=i;
        arr[i].rank=0;
    }
    quick_point_sort(arr,0,n-1);
    for(int i=1; i<n; i++){
        arr[i].rank=arr[i-1].rank;
        if(arr[i].x!=arr[i-1].x)arr[i].rank++;
    }
    int print_arr[n];
    for(int i=0; i<n; i++) print_arr[arr[i].index] = arr[i].rank;
    for(int i=0; i<n; i++){
        printf("%d",print_arr[i]);
        if(i<n-1) printf(" ");
    }
}