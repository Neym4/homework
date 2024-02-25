#include<stdio.h>

int main(){
    int a;
    printf("Enter a: ");
    scanf("%d", &a);
    while(a>0){
        if(a%2==1){
            printf("No");
            return 0;
        }
        a /=10;
    }
    printf("Yes");
    return 0;
}
