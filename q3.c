#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int x) {
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

struct node* insert(struct node *root, int x) {
    if (!root) return create(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}

struct node* minNode(struct node *root) {
    while (root->left) root = root->left;
    return root;
}

struct node* delete(struct node *root, int x) {
    if (!root) return root;
    if (x < root->data) root->left = delete(root->left, x);
    else if (x > root->data) root->right = delete(root->right, x);
    else {
        if (!root->left) {
            struct node *t = root->right;
            free(root);
            return t;
        }
        if (!root->right) {
            struct node *t = root->left;
            free(root);
            return t;
        }
        struct node *t = minNode(root->right);
        root->data = t->data;
        root->right = delete(root->right, t->data);
    }
    return root;
}

int maxDepth(struct node *root) {
    if (!root) return 0;
    int L = maxDepth(root->left);
    int R = maxDepth(root->right);
    return (L > R ? L : R) + 1;
}

int minDepth(struct node *root) {
    if (!root) return 0;
    int L = minDepth(root->left);
    int R = minDepth(root->right);
    if (!root->left) return R + 1;
    if (!root->right) return L + 1;
    return (L < R ? L : R) + 1;
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    root = delete(root, 40);

    printf("Max Depth: %d\n", maxDepth(root));
    printf("Min Depth: %d\n", minDepth(root));

    return 0;
}
