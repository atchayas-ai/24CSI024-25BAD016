//Challenge Yourself 1
//This program creates an AVL tree by inserting the given numbers while maintaining balance using rotations. 
//Then, it searches for the given key and prints whether the key is found or not.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node *left, *right;
    int height;
};
int height(struct Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
struct Node* createNode(int key) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *t = x->right;
    x->right = y;
    y->left = t;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *t = y->left;
    y->left = x;
    x->right = t;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
int getBalance(struct Node *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}
struct Node* insert(struct Node *node, int key) {
    if (node == NULL)
        return createNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
int search(struct Node *root, int key) {
    if (root == NULL)
        return 0;
    if (root->key == key)
        return 1;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}
int main() {
    struct Node *root = NULL;
    int x, k;
    while (1) {
        scanf("%d", &x);
        if (x == -1)
            break;
        root = insert(root, x);
    }
    scanf("%d", &k);
    if (search(root, k))
        printf("Key %d found in the AVL tree.", k);
    else
        printf("Key %d not found in the AVL tree.", k);

    return 0;
}