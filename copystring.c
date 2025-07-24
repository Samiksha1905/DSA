#include<stdio.h>
int main(){
    char c[]={"Hello CSVTU"};
    char copy[100];

    int i=0;
    while(c[i]!='\0'){
        copy[i]=c[i];
        i++;
    }
    copy[i]='\0';

    printf("%s ",copy);
    return 0;
}