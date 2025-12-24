#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node* insertHead(node* head, int data);
node* insertAfter(node* head, int key, int data);
node* deleteNode(node* head, int key);
void printList(node* head);

int main(void) {
    node* head = NULL;

    head = insertHead(head, 10);
    head = insertHead(head, 20);
    head = insertHead(head, 30);

    printf("Initial list: ");
    printList(head);

    head = insertAfter(head, 20, 25);
    printf("After inserting 25 after 20: ");
    printList(head);

    head = deleteNode(head, 20);
    printf("After deleting 20: ");
    printList(head);

    head = deleteNode(head, 30);
    printf("After deleting 30 (head): ");
    printList(head);

    return 0;
}

node* insertHead(node* head, int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL) {
        head->prev = temp;
    }
    
    return temp; 
}

node* insertAfter(node* head, int key, int data) {
    node* temp = head;
    
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in list.\n", key);
        return head;
    }

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return head;
}

node* deleteNode(node* head, int key) {
    node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return head;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    return head;
}

void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
