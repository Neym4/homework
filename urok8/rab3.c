#include<stdio.h>

int find_max_array(int size, int a[]){
    int max = a[0];
    for(int i = 0; i < size; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

int main(){
    int mass[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 564, 5};
    printf("%d", find_max_array(20,mass));
    return 0;
}
