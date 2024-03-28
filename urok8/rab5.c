#include<stdio.h>

void change_max_min(int size, int* a){
    int max = 0, min = 0;
    for(int i = 0; i<size; i++){
        if(a[i]<a[min]){
            min = i;
        }
        if(a[i]>a[min]){
            max = i;
        }
    }
    int tmp;
    tmp = a[min];
    a[min] = a[max];
    a[max] = tmp;
}

int main(){
    int mass[] = {1,2,3,4,5,6,7,8,9,10};
    change_max_min(10, mass);
    for(int i =0; i<10; i++){
        printf("%d ", mass[i]);
    }
    return 0;
}
