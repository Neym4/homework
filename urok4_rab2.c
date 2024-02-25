#include<stdio.h>


int main(){
    int a,b,c;
    printf("Enter a: ");
    scanf("%d",&a);
    if(a<0){
        printf("a can`t be <0");
        return 0;
    }
    b = a/1000;
    c = a/100;
    if(b==0 && (c!=0 && c<=9)){
        printf("YES");
    }
    else{
        printf("NO");
    }
}
