#include<stdio.h>

void print_num(int n, int m){
    if(n<m){
        printf("%d ", n);
        print_num(n+1,m);
    }
    if(n>m){
        printf("%d ", n);
        print_num(n-1,m);
    
    }
    if(n==m){printf("%d", n);} return;
}

int main(){
    print_num(7,2);
}
