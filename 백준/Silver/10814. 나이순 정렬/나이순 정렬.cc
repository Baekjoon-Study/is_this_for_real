#include <stdio.h>
#include <string.h>

typedef struct{
    int age;
    int num;
    char name[101];
}Member;

void new_member(Member *New, int Age, int Num, char *Name){
    New->age = Age;
    New->num = Num;
    strcpy(New->name, Name);
}

void swap_member(Member *m1, Member *m2){
    int temp1 = m1->age;
    m1->age = m2->age;
    m2->age = temp1;

    temp1 = m1->num;
    m1->num = m2->num;
    m2->num = temp1;

    char temp2[101];
    strcpy(temp2, m1->name);
    strcpy(m1->name, m2->name);
    strcpy(m2->name, temp2);
    
}

int compare_member(Member *m1, Member *m2){
    if(m1->age > m2->age) return 1;
    if(m1->age == m2->age) return m1->num > m2->num;
    return 0;
}

void print_member(Member *member){
    printf("%d %s\n",member->age,member->name);
}

int partition(Member *list, int low, int high){
    Member pivot = list[(low+high)/2];
    while(low<=high){
        while(compare_member(&pivot,&list[low]))low++;
        while(compare_member(&list[high],&pivot))high--;
        if(low<=high){
            if(low<high){
                Member temp = list[low];
                list[low] = list[high];
                list[high] = temp;
            }
            low++;
            high--;
        }
    }
    return low;
}

void quick_sort(Member *list, int low, int high){
    if(low<high){
        int pivot  = partition(list,low,high);
        quick_sort(list, low, pivot-1);
        quick_sort(list, pivot, high);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    Member member_list[n];
    for(int i=0; i<n; i++){
        int age;
        char name[101];
        scanf("%d %s",&age,name);
        new_member(&member_list[i],age,i,name);
    }
    quick_sort(member_list,0,n-1);
    for(int i=0; i<n; i++) print_member(&member_list[i]);
}