#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* insertEnd(node* head, int data);
node* deleteNode(node* head, int key);
void printList(node* head);

int main(void) {
    node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    printf("Initial List: ");
    printList(head);

    head = deleteNode(head, 10);
    printf("After deleting 10 (head): ");
    printList(head);

    head = deleteNode(head, 30);
    printf("After deleting 30: ");
    printList(head);

    head = deleteNode(head, 40);
    printf("After deleting 40 (last): ");
    printList(head);

    return 0;
}

node* insertEnd(node* head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

node* deleteNode(node* head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    node* temp = head;
    node* prev = NULL;

    if (head->data == key) {
        if (head->next == head) {
            free(head);
            return NULL;
        }
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        return head;
    }

    while (temp->next != head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Element %d not found.\n", key);
    }

    return head;
}

void printList(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(HEAD)\n");
}
