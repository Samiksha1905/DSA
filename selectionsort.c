#include<stdio.h>
int main(){
    int a[5]={64,25,12,22,11};

    for(int i=0;i<4;i++){
        int min=i;     //unsorted part starting
        for(int j=i+1;j<5;j++)
        if(a[j]<a[min])
        min=j;
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
        }
        for(int i=0;i<5;i++)
        printf("%d ",a[i]);
        return 0;
    }
