#include<stdio.h>

int find_max_array(int size, int a[]){
    
    for(int i = 0; i < size; i++){
        for(int j = i+1; j<size-1; j++){
            if(a[i]==a[j]){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int mass[] = {1,2,1,4,5};
    if(find_max_array(sizeof(mass)/sizeof(mass[0]), mass) == 1){
        printf("Yes");
    }else{
        printf("No");
    }
}
