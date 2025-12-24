#include <stdio.h>

int cnt = 0;

void runHanoi(int n, char from, char to, char aux);

int main(void) {
    int n = 4;

    runHanoi(n, 'A', 'C', 'B');
    
    printf("\nTotal Moves: %d\n", cnt);

    return 0;
}

void runHanoi(int n, char from, char to, char aux) {
    if (n == 0) {
        return;
    }

    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        cnt++;
        return;
    }

    runHanoi(n - 1, from, aux, to);
    
    printf("Move disk %d from %c to %c\n", n, from, to);
    cnt++;

    runHanoi(n - 1, aux, to, from);
}
