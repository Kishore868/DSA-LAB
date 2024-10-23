


#include <stdio.h>



void insert_rear(int q[], int *rear,int *count,int size,int item)
 {
    if (*count==size)
        {
        printf("Queue is overflow\n");
    } else {
        (*rear)+=1;
        *rear=*rear%size;
        q[*rear] = item;
        *count+=1;
        printf("Inserted %d\n", item);
    }
}

int delete_front(int q[], int *front, int *count,int size) {
    if (*count==0) {
        printf("Queue is underflow\n");
        return -1;
    } else {
        int del_item = q[*front];
        *front=(*front+1)%size;
        *count-=1;
        printf("Deleted %d\n", del_item);

        return del_item;
    }
}

void display(int q[], int *front, int *count,int size) {
    if (*count==0) {
        printf("Queue is empty\n");
    } else {
        int i=*front;
        printf("Queue elements: \n");
        for (int j = 0; j < *count; j++) {
            printf("%d \n", q[i]);
            i=(i+1)%size;
        }
        printf("\n");
    }
}

int main() {
    int size;
    int front = 0;
    int rear = -1;
    int choice, item;
    int count=0;
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
                insert_rear(q, &rear, &count, size,item);
                break;
            case 2:
                delete_front(q, &front,&count,size);

                break;
            case 3:
                display(q, &front,&count,size);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
