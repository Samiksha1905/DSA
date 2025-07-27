#include <stdio.h>      // For input/output 
#include <stdlib.h>     // For malloc and free 
 
// Define a node structure 
struct Node { 
    int data;                   // Node data 
    struct Node *left, *right; // Left and right child pointers 
}; 
 
// Create a new node 
struct Node* create(int value) { 
    struct Node* n = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory 
    n->data = value;         // Set data 
    n->left = n->right = NULL; // Initialize children 
    return n;                // Return new node 
} 
 
// Insert a value into BST 
struct Node* insert(struct Node* root, int value) { 
    if (root == NULL) return create(value);        // Empty spot found 
    if (value < root->data)                        // Go left 
        root->left = insert(root->left, value); 
    else if (value > root->data)                   // Go right 
        root->right = insert(root->right, value); 
    return root;                                   // Return unchanged root 
} 
 
// In-order traversal 
void inorder(struct Node* root) { 
    if (root) {                    // If not null 
        inorder(root->left);       // Visit left 
        printf("%d ", root->data); // Print data 
        inorder(root->right);      // Visit right 
    } 
} 
 
// Search for a key 
struct Node* search(struct Node* root, int key) { 
    if (!root || root->data == key) return root;    // Found or NULL 
    if (key < root->data) return search(root->left, key); // Left 
    return search(root->right, key);                // Right 
} 
 
// Find min value node 
struct Node* findMin(struct Node* node) { 
    while (node->left) node = node->left;   // Go to leftmost node 
    return node; 
} 
 
// Delete a node 
struct Node* delete(struct Node* root, int key) { 
    if (!root) return NULL;                         // Base case 
    if (key < root->data)                           // Go left 
        root->left = delete(root->left, key); 
    else if (key > root->data)                      // Go right 
        root->right = delete(root->right, key); 
    else { 
        if (!root->left) {                          // One or no child 
            struct Node* temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (!root->right) { 
            struct Node* temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct Node* temp = findMin(root->right);   // Two children 
        root->data = temp->data;                    // Copy inorder successor 
        root->right = delete(root->right, temp->data); // Delete successor 
    } 
    return root; 
} 
 
// Main function 
int main() { 
    struct Node* root = NULL;              // Empty tree 
 
    root = insert(root, 40);               // Insert values 
    insert(root, 20); 
    insert(root, 60); 
    insert(root, 10); 
    insert(root, 30); 
    insert(root, 50); 
    insert(root, 70); 
 
    printf("In-order: "); 
    inorder(root);                         // Print tree 
    printf("\n"); 
 
    if (search(root, 30))                  // Search key 
        printf("30 found\n"); 
    else 
        printf("30 not found\n"); 
 
    root = delete(root, 60);               // Delete node 
printf("After deleting 60: "); 
inorder(root);                         
printf("\n"); 
return 0;                              
// Print updated tree
}