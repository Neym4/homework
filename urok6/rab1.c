#include<stdio.h>

void print_num(int n){
    if(n == 0) return;
    print_num(n/10);
    printf("%d ", n%10);
}
int main(){
    print_num(54321);
}
