#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

int preIndex = 0;

struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


int search(char inorder[], int start, int end, char value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(char inorder[], char preorder[], int start, int end) {
    if (start > end)
        return NULL;

    
    char curr = preorder[preIndex++];
    struct Node* node = newNode(curr);

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, curr);

    node->left = buildTree(inorder, preorder, start, inIndex - 1);
    node->right = buildTree(inorder, preorder, inIndex + 1, end);

    return node;
}


void printInorder(struct Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%c ", root->data);
    printInorder(root->right);
}

int main() {
    char inorder[] = {'D','B','E','A','F','C'};
    char preorder[] = {'A','B','D','E','C','F'};
    int n = 6;

    struct Node* root = buildTree(inorder, preorder, 0, n - 1);

    printf("Inorder traversal of constructed tree:\n");
    printInorder(root);

    return 0;
}