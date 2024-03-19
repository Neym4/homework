#include<stdio.h>
#define SIZE_ARRAY  5
void average(int *mass){
    float sum = 0;
    for(int i = 0; i<SIZE_ARRAY; ++i){
        sum += mass[i];
    }
    printf("\nAverage: %.3f", sum/SIZE_ARRAY);
}

int main(){
    int mass[SIZE_ARRAY];
    printf("Enter 5 elements of massive\n");
    for(int i = 0; i<SIZE_ARRAY; ++i){
        scanf("%d", &mass[i]);
    }
    average(mass);
}
