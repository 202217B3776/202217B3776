#include <stdio.h>
#include <stdlib.h>

#define n 5

void insert();
void delete();
void display();

int queue[n], ch = 1, front = 0, rear = 0, i, j = 1;

int main() {
    printf("Queue using Array");
    printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit");

    while (ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong Choice: Please see the options");
        }
    }

    return 0;
}

void insert() {
    if (rear == n) {
        printf("\nQueue is Full");
    } else {
        printf("\nEnter no %d: ", j++);
        scanf("%d", &queue[rear++]);
    }
}

void delete() {
    if (front == rear) {
        printf("\nQueue is empty");
    } else {
        printf("\nDeleted Element is %d", queue[front++]);
        // After deletion, if the queue becomes empty, reset front and rear
        if (front == rear) {
            front = rear = 0;
        }
    }
}

void display() {
    if (front == rear) {
        printf("\nQueue is Empty");
    } else {
        printf("\nQueue Elements are:\n");
        for (i = front; i < rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
