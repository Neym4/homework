#include<stdio.h>
int nod(int num1, int num2){
    int del = 1;
    int chisla = 0;
    for(int i = 0; i<num1; i++){
        chisla += 1;
        if(num1%chisla == 0 && num2%chisla ==0){
            del = chisla;
        }
    }
    return del;
}

int main(){
    int num1 = 14, num2 = 21;
    //scanf("%d %d\n", num1, num2);
    printf("%d", nod(num1, num2));
    return 0;
}
