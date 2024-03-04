#include<stdio.h>

int is_happy_number(int n){
    int sum = 0;
    int proizved = 1;
    int chislo = 0;
    while(n>=1){
        chislo = n%10;
        sum += chislo;
        proizved *= chislo;
        n = n/10;
    }
    if(sum == proizved){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){
    int n = 528;
    if(is_happy_number(n)==1){
        printf("Yes");
    }
    else{
        printf("No");
    }
}
