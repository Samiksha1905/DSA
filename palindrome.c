#include<stdio.h>
int main(){
    char str[100]={"ada"};
    int start,end,isPalindrome=1,size=3;
    start=0;
    end=size-1;
    while(start<end){
        if(str[start]!=str[end]){
            isPalindrome=0;
            break;
        }
        start++;
        end--;
    }
    if(isPalindrome){
        printf("The string is a Palindrome");
    }
    else{
        printf("The string is not a palindrome");
    }
    return 0;
}