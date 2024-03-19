#include<stdio.h>
#define SIZE_ARRAY  5
void min_element(int *mass){
    int min = mass[0];
    for(int i = 0; i<SIZE_ARRAY; ++i){
        if(mass[i]<min){
            min = mass[i];
        }
    }
    printf("\nMin element: %d", min);
}

int main(){
    int mass[SIZE_ARRAY];
    printf("Enter 5 elements of massive\n");
    for(int i = 0; i<SIZE_ARRAY; ++i){
        scanf("%d", &mass[i]);
    }
    min_element(mass);
}
