#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
void preorder(struct Node*root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
int main(){
    struct Node *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    printf("Inorder Traversal: ");
    inorder(root);

    printf("Preorder traversal: ");
    preorder(root);

    printf("Postorder traversal: ");
    postorder(root);
    return 0;
}