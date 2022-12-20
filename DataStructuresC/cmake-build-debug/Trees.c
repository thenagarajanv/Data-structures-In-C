#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode *left, *right;
};
struct tnode *root = NULL;

struct tnode *createNode(int data) {
    struct tnode *newNode;
    newNode = (struct tnode *) malloc(sizeof(struct tnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return (newNode);
}

void insertion(struct tnode **node, int data) {
    if (!*node) {
        *node = createNode(data);
    } else if (data < (*node)->data) {
        insertion(&((*node)->left), data);
    } else if (data > (*node)->data) {
        insertion(&(*node)->right, data);
    }
}

void postOrder(struct tnode *node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d -> ", node->data);
    }
}

void preOrder(struct tnode *node) {
    if (node) {
        printf("%d -> ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void InOrder(struct tnode *node) {
    if (node) {
        preOrder(node->left);
        printf("%d -> ", node->data);
        preOrder(node->right);
    }
}
int maxdepth(struct tnode *node) {
    if (node == NULL) {
        return 0;
    } else {
        int rmaxdepth = maxdepth(node->right);
        int lmaxdepth = maxdepth(node->left);
        if (lmaxdepth > rmaxdepth) {
            return lmaxdepth + 1;
        } else {
            return rmaxdepth + 1;
        }
    }
}