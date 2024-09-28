#include <stdio.h>

typedef struct {
    int x, y;
} Point;

// 두 점을 비교하는 함수: 첫 번째가 더 크면 양수, 같으면 0, 작으면 음수 반환
int compare(Point *a, Point *b) {
    Point A = *a;
    Point B = *b;

    if (A.x > B.x) return 1;
    if (A.x < B.x) return -1;
    if (A.y > B.y) return 1;
    if (A.y < B.y) return -1;
    return 0;  // x, y 값이 모두 같을 경우
}

// 분할 함수 (Partitioning)
int partition(Point arr[], int low, int high) {
    Point pivot = arr[(low + high) / 2];  // 중간 값으로 피벗 설정
    while (low <= high) {
        // 피벗보다 작은 값 찾기
        while (compare(&arr[low], &pivot) < 0) low++;
        // 피벗보다 큰 값 찾기
        while (compare(&arr[high], &pivot) > 0) high--;

        if (low <= high) {
            // low와 high가 엇갈리지 않은 경우 교환
            Point temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
    return low;  // 분할된 배열의 새로운 기준점 반환
}

// 퀵 정렬 함수
void quick_sort(Point arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);  // 분할된 피벗 위치
        quick_sort(arr, low, pivot - 1);        // 왼쪽 부분 배열 정렬
        quick_sort(arr, pivot, high);           // 오른쪽 부분 배열 정렬
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    Point arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    quick_sort(arr, 0, n - 1);  // 퀵 정렬 실행

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }

    return 0;
}
