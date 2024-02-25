#include<stdio.h>

int SumSquare(int a1, int b1){
    int sum = 0;
    for(int i = a1; i<=b1; i++){
        sum += i*i;
    }
    return sum;
}

int main(){
    int a, b;
    printf("Enter a and b(a<=b): ");
    scanf("%d%d", &a, &b);
    if(a>b){
        printf("a>b, it is not correct");
        return 0;
    }
    printf("%d %d = %d", a, b, SumSquare(a,b));
    return 0;
}
