#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertLevelOrder(int arr[], int i, int n) {
    Node* root = NULL;

    if (i < n) {
        root = newNode(arr[i]);

        root->left = insertLevelOrder(arr, 2 * i + 1, n);

        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Giris Dizisi: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    Node* root = insertLevelOrder(arr, 0, n);

    printf("Olusturulan Agacin InOrder Gezintisi: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
