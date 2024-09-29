#include <stdio.h>
typedef struct{
    int x, y;
}Point;
int compare(Point *a, Point *b){
    Point A = *a;
    Point B = *b;
    if(A.y>B.y) return 1;
    if(A.y==B.y) return A.x>B.x;
    return 0;
}
int partition(Point arr[], int low, int high){
    Point pivot = arr[(low+high)/2];
    while(low<high){
        while(compare(&pivot,&arr[low])) low++;
        while(compare(&arr[high],&pivot)) high--;
        if(low<high){
            Point temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    return low;
}
void quick_sort(Point arr[], int low, int high){
    if(low<high){
        int pivot = partition(arr,low,high);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,high);
    }
}
int main(void){
    int n;
    scanf("%d",&n);
    Point arr[n];
    for(int i=0; i<n; i++) scanf("%d %d",&arr[i].x,&arr[i].y);
    quick_sort(arr,0,n-1);
    for(int i=0; i<n; i++) printf("%d %d\n",arr[i].x,arr[i].y);
}