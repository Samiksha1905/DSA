#include<stdio.h>
#include<string.h>
int main(){
    char c[]={"Hello"};
    int length=0;
    while(c[length]!='\0'){
        length++;
    }
    printf("%d",length);
    printf("\nReversed string: ");

    for(int i=length-1;i>=0;i--){
        printf("%c",c[i]);
    }
    return 0;
}