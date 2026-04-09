#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

int postIndex;


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


struct Node* buildTree(char inorder[], char postorder[], int start, int end) {
    if (start > end)
        return NULL;

    
    char curr = postorder[postIndex--];
    struct Node* node = newNode(curr);

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, curr);

    
    node->right = buildTree(inorder, postorder, inIndex + 1, end);
    node->left  = buildTree(inorder, postorder, start, inIndex - 1);

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
    char postorder[] = {'D','E','B','F','C','A'};
    int n = 6;

    postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1);

    printf("Inorder traversal:\n");
    printInorder(root);

    return 0;
}