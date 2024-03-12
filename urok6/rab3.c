#include<stdio.h>

void binaryNum(int n, int m){
    if(n<=0){
        printf("%d ", m); 
        return;
    }
    if(n%2==1){
        m++;
    }
    binaryNum(n/2, m);
}

int main(){
    binaryNum(255,0); 
}
