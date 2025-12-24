#include <stdio.h>

#define MAX 100

void insert(int arr[], int *n, int pos, int val);
void delete(int arr[], int *n, int pos);
void display(int arr[], int n);

int main(void) {
    int arr[MAX];
    int n = 0;
    int choice, pos, val;

    while (1) {
        printf("\n1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position (0 to %d) and value: ", n);
                scanf("%d %d", &pos, &val);
                insert(arr, &n, pos, val);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

void insert(int arr[], int *n, int pos, int val) {
    if (*n >= MAX) {
        printf("Array is full.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    (*n)++;
    
    printf("Inserted %d at position %d.\n", val, pos);
}

void delete(int arr[], int *n, int pos) {
    if (*n == 0) {
        printf("Array is empty.\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }

    int deleted = arr[pos];

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
    printf("Deleted %d from position %d.\n", deleted, pos);
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
