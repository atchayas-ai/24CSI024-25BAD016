//Daily Challenge 1
//This program inserts all product prices into an AVL tree while keeping it balanced. Then it counts how many
//prices are strictly greater than the given value x.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key, height;
    struct Node *left, *right;
};
int height(struct Node *n) {
    return n == NULL ? 0 : n->height;
}
int max(int a, int b) {
    return a > b ? a : b;
}
struct Node* createNode(int key) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->key = key;
    n->height = 1;
    n->left = n->right = NULL;
    return n;
}
int balance(struct Node *n) {
    return n == NULL ? 0 : height(n->left) - height(n->right);
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
struct Node* insert(struct Node *root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    root->height = 1 + max(height(root->left), height(root->right));
    int b = balance(root);
    if (b > 1 && key < root->left->key)
        return rightRotate(root);
    if (b < -1 && key >= root->right->key)
        return leftRotate(root);
    if (b > 1 && key >= root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (b < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
int countGreater(struct Node *root, int x) {
    if (root == NULL)
        return 0;
    if (root->key > x)
        return 1 + countGreater(root->left, x)
                 + countGreater(root->right, x);
    return countGreater(root->right, x);
}
int main() {
    struct Node *root = NULL;
    int n, key, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }
    scanf("%d", &x);
    int count = countGreater(root, x);
    printf("Number of elements greater than %d are %d", x, count);
    return 0;
}