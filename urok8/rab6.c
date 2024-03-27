#include<stdio.h>

int over_average(int lengh_str,int lengh_row, int a[lengh_str][lengh_row]){
    int mass = 0, j = 0;
    for(int i = 0; i<lengh_row; i++){
        j = i;
        mass += a[i][j];
    }
    mass = mass /lengh_row;
    int count = 0;
    for(int i = 0; i<lengh_str;i++){
        for(int j= 0; j<lengh_row;j++){
            if(a[i][j]>mass){
                count++;
            }
        }
    }
}

int main(){
    int mass[5][5] = {{1,1,1,1,1},
                    {2,2,2,2,2},
                    {3,3,3,3,3},
                    {4,4,4,4,4},
                    {5,5,5,5,5}};
    over_average(5,5, mass);
}
