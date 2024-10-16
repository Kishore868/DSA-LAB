


#include <stdio.h>



void insert_rear(int q[], int item, int size, int *rear) {
    if (*rear == size - 1) {
        printf("Queue is overflow\n");
    } else {
        (*rear)++;
        q[*rear] = item;
        printf("Inserted %d\n", item);
    }
}

int delete_front(int q[], int *front, int *rear) {
    if (*front > *rear) {
        printf("Queue is underflow\n");
        return -1;
    } else {
        int del_item = q[*front];
        (*front)++;
        printf("Deleted %d\n", del_item);
        return del_item;
    }
}

void display(int q[], int front, int rear) {
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    int front = 0;
    int rear = -1;
    int choice, item;
    printf("Enter no of elements\n");
    scanf("%d",&size);
    int q[size];

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to insert: ");
                scanf("%d", &item);
                insert_rear(q, item, size, &rear);
                break;
            case 2:
                delete_front(q, &front, &rear);
                break;
            case 3:
                display(q, front, rear);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
