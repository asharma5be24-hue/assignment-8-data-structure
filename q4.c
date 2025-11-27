#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int isBSTUtil(struct node* root, int min, int max) {
    if (root == NULL) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

int isBST(struct node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    struct node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if (isBST(root))
        printf("BST");
    else
        printf("Not BST");

    return 0;
}
