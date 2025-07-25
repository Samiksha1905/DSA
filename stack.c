#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
    int items[MAX];
    int top;
}Stack;
void init (Stack *s){
    s->top=-1;
}
int isFull(Stack *s){
    return s->top==MAX-1;
}
int isEmpty(Stack *s){
    return s->top==-1;
}
void push(Stack *s,int value){
    if(isFull(s)){
        printf("Stack Overflow!\n",value);
        return;
    }
    s->items[++(s->top)]=value;
    printf("%d pushed to stack\n",value);
}
int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}
int peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}
void display(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements(top to bottom): \n");
    for(int i=s->top;i>=0;i--){
        printf("%d\n",s->items[i]);
    }
}
int main(){
    Stack s;
    init(&s);
    int choice,value;
    do{
        printf("\nStack Menu: \n");
        printf("1.Push\n 2.Pop\n 3.Peek\n 4.Display\n 5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter value to push: ");
            scanf("%d",&value);
            push(&s,value);
            break;

            case 2:
            value=pop(&s);
            if(value!=-1)
            printf("Popped:%d\n",value);
            break;

            case 3:
            value=peek(&s);
            if(value!=-1)
            printf("Top element:%d\n",value);
            break;

            case 4:
            display(&s);
            break;

            case 5:
            printf("Exiting\n");
            break;
            default:
            printf("Invalid choice\n");
        }
    }
    while(choice!=5);
    return 0;
}