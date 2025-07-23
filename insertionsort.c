#include<stdio.h>
    void printArray(int arr[],int size){
        for(int i=0;i<size;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    void insertionSort(int arr[],int size){
        for(int step=1;step<size;step++){
            int key=arr[step];
            int j=step-1;
            while(j>=0 && key<arr[j]){
                arr[j+1]=arr[j];
                --j;
            }
            arr[j+1]=key;
        }
    }
    int main(){
        int data[]={9,5,1,4,3};
        int size=sizeof(data)/sizeof(data[0]);
        insertionSort(data,size);
        printf("Sorted array is: \n");
        printArray(data,size);
        return 0;
    }