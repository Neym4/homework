#include<stdio.h>

int sort_even_odd(int n, int a[]){
    int i, j, temp;
    for ( i = 0; i < n; i++ ) {
        if ( a[i] % 2 != 0 ) {
            for ( j = i; j < n; j++ ) {
                if ( a[j] % 2 == 0 ) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    break;
                }
            }
        }
    }
    for(int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int mass[] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
    sort_even_odd(20, mass);
    printf("Hello world!");
}
