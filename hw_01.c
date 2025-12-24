#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;

Node* createNode(int row, int col, int value);
Node* insertNode(Node* head, int row, int col, int value);
void printList(Node* head);

int main(void) {
    int sparseMatrix[5][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0},
        {4, 0, 0, 0, 8}
    };

    Node* head = NULL;
    int rows = 5;
    int cols = 5;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                head = insertNode(head, i, j, sparseMatrix[i][j]);
            }
        }
    }

    printList(head);

    return 0;
}

Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    printf("Row\tCol\tValue\n");
    printf("---\t---\t-----\n");
    
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
    printf("\n");
}
