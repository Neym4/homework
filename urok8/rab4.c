#include<stdio.h>

int find_max_array(int size, int a[]){
    
    for(int i = 0; i < size; i++){
        for(int j = i+1; j<size-1; j++){
            if(a[i]==a[j]){
                printf("Yes");
                return 0;
            }
        }
    }
    printf("no");
}

int main(){
    int mass[] = {1,2,1,4,5};

    // for(int i = 0; i<100; i++){
    //     mass[i] = i;
    // }
    find_max_array(100, mass);
}
