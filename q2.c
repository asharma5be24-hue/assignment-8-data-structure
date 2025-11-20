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
    if (root == NULL) return create(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

struct node* searchR(struct node *root, int x) {
    if (!root || root->data == x) return root;
    if (x < root->data) return searchR(root->left, x);
    else return searchR(root->right, x);
}

struct node* searchNR(struct node *root, int x) {
    while (root) {
        if (x == root->data) return root;
        else if (x < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

struct node* minNode(struct node *root) {
    while (root && root->left) root = root->left;
    return root;
}

struct node* maxNode(struct node *root) {
    while (root && root->right) root = root->right;
    return root;
}

struct node* inorderSuccessor(struct node *root, struct node *x) {
    if (x->right) return minNode(x->right);
    struct node *succ = NULL;
    while (root) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        } else if (x->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

struct node* inorderPredecessor(struct node *root, struct node *x) {
    if (x->left) return maxNode(x->left);
    struct node *pred = NULL;
    while (root) {
        if (x->data > root->data) {
            pred = root;
            root = root->right;
        } else if (x->data < root->data)
            root = root->left;
        else break;
    }
    return pred;
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

    struct node *n = searchR(root, 40);
    if (n) printf("Found Recursively: %d\n", n->data);

    n = searchNR(root, 60);
    if (n) printf("Found Non-Recursively: %d\n", n->data);

    printf("Minimum: %d\n", minNode(root)->data);
    printf("Maximum: %d\n", maxNode(root)->data);

    struct node *x = searchR(root, 50);
    struct node *s = inorderSuccessor(root, x);
    struct node *p = inorderPredecessor(root, x);

    if (s) printf("Successor of 50: %d\n", s->data);
    if (p) printf("Predecessor of 50: %d\n", p->data);

    return 0;
}
