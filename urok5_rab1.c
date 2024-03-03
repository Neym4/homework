#include<stdio.h>

int zernaNaKletke(int n){
    int m = 1;
    for(int i =1; i<n; i++){
        m *= 2;
    }
    return m;
}

int main(){
    int m = 28;
    printf("%d", zernaNaKletke(m));
}
