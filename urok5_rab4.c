#include<stdio.h>

int gauss_fomul(int n){
    return (n*(n+1))/2;
}
//первая по формуле гаусса(ура математика...)
int formul_sum(int n){
    int sum = 0;
    for(int i = 1; i<=n; i++){
        sum += i;
    }
    return sum;
}

int main(){
    int n = 100;
    printf("%d %d", gauss_fomul(n), formul_sum(n));
}
