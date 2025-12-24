#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int maxHeap[SIZE];
int minHeap[SIZE];
int maxCount = 0;
int minCount = 0;

void insertMax(int val);
void deleteMax();
void insertMin(int val);
void deleteMin();
void display();

int main(void) {
    int choice, val;

    while (1) {
        printf("\n1. Insert Max Heap\n");
        printf("2. Delete Max Heap\n");
        printf("3. Insert Min Heap\n");
        printf("4. Delete Min Heap\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &val);
                insertMax(val);
                break;
            case 2:
                deleteMax();
                break;
            case 3:
                printf("Value: ");
                scanf("%d", &val);
                insertMin(val);
                break;
            case 4:
                deleteMin();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Wrong choice.\n");
        }
    }
    return 0;
}

void insertMax(int val) {
    if (maxCount == SIZE) {
        printf("Heap full.\n");
        return;
    }

    int i = maxCount;
    maxHeap[i] = val;
    maxCount++;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (maxHeap[i] > maxHeap[parent]) {
            int temp = maxHeap[i];
            maxHeap[i] = maxHeap[parent];
            maxHeap[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

void deleteMax() {
    if (maxCount == 0) {
        printf("Heap empty.\n");
        return;
    }

    printf("Deleted: %d\n", maxHeap[0]);
    
    maxHeap[0] = maxHeap[maxCount - 1];
    maxCount--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < maxCount && maxHeap[left] > maxHeap[largest]) {
            largest = left;
        }
        if (right < maxCount && maxHeap[right] > maxHeap[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = maxHeap[i];
            maxHeap[i] = maxHeap[largest];
            maxHeap[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

void insertMin(int val) {
    if (minCount == SIZE) {
        printf("Heap full.\n");
        return;
    }

    int i = minCount;
    minHeap[i] = val;
    minCount++;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (minHeap[i] < minHeap[parent]) {
            int temp = minHeap[i];
            minHeap[i] = minHeap[parent];
            minHeap[parent] = temp;
            i = parent;
        } else {
            break;
        }
    }
}

void deleteMin() {
    if (minCount == 0) {
        printf("Heap empty.\n");
        return;
    }

    printf("Deleted: %d\n", minHeap[0]);
    
    minHeap[0] = minHeap[minCount - 1];
    minCount--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < minCount && minHeap[left] < minHeap[smallest]) {
            smallest = left;
        }
        if (right < minCount && minHeap[right] < minHeap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            int temp = minHeap[i];
            minHeap[i] = minHeap[smallest];
            minHeap[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
}

void display() {
    int i;
    printf("Max Heap: ");
    for (i = 0; i < maxCount; i++) {
        printf("%d ", maxHeap[i]);
    }
    printf("\n");

    printf("Min Heap: ");
    for (i = 0; i < minCount; i++) {
        printf("%d ", minHeap[i]);
    }
    printf("\n");
}
