#include<stdio.h>

void sort_array(int size, int a[]){
    int count;
    for(int i = 0; i<size-1; i++){
        for(int j = i; j<size; j++){
            if(a[i] >a[j]){
                count = a[i];
                a[i] = a[j];
                a[j] = count;
            }
        }
    }
    for(int i = 0; i<size; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int mass[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    sort_array(20, mass);
    printf("Hello world!");
    return 0;
}
