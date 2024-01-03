#include <stdio.h>
#include <malloc.h>
#include <intrin.h>

#define MAX_SIZE_OF_CONTENT 100
#define MAX_ELEMENTS 300

typedef struct Node_T {
    char *content;
    struct Node_T *right, *left;
}Node_T;

void postOrder(Node_T *root) {
    if(root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%s ", root->content);
}

Node_T * createBinTree() {
    Node_T *p;

    char *content = (char *)malloc(sizeof(char) * MAX_SIZE_OF_CONTENT);
    scanf("%s", content);
    if(strcmp(content, "*") == 0)
        return NULL;

    p = (Node_T *)malloc(sizeof(Node_T));
    p->content = (char *)malloc(sizeof(char) * MAX_SIZE_OF_CONTENT);

    strcpy(p->content, content);
    p->left = createBinTree();
    p->right = createBinTree();

    return p;
}

void count_Leafs(Node_T *root, int *leaf) {
    if(root->left == NULL && root->right == NULL) (*leaf)++;

    else if(root->left == NULL)
        count_Leafs(root->right, leaf);
    else if(root->right == NULL)
        count_Leafs(root->left, leaf);
    else {
        count_Leafs(root->left, leaf);
        count_Leafs(root->right, leaf);
    }
}

void print_path(Node_T *root, int *array, int n) {
    if (root == NULL)
        return;

    array[n++] = atoi(root->content);
    if (root->left == NULL && root->right == NULL) {
        for(int i = 0; i < n; i++)
            printf("%d ", array[i]);
        puts("\n");
    }

    else {
        print_path(root->left, array, n);
        print_path(root->right, array, n);
    }
}

void all_paths(Node_T *root) {
    int *path = malloc(MAX_ELEMENTS);
    print_path(root, path, 0);
}

void tree_mirrored(Node_T *root, Node_T *head) {
    if (root == NULL) {
        puts("\n");
        postOrder(head);
        return;
    }

    else {
        Node_T *temp;

        tree_mirrored(root->left, head);
        tree_mirrored(root->right, head);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int main() {
    Node_T *root = createBinTree();

    int initial_leafs = 0;
    int *number_of_leafs;
    number_of_leafs = &initial_leafs;

    count_Leafs(root, number_of_leafs);
    printf("Number of leafs: %d\n", *number_of_leafs);

    printf("Root-to-leaf paths:\n");
    all_paths(root);

    printf("Post Order Traversal: ");
    Node_T *head = root;
    postOrder(root);
    printf("\nMirrored traversal:\n");
    tree_mirrored(root, head);

    return 0;
}
