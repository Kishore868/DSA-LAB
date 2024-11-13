#include <stdio.h>
#include <stdlib.h>
struct node {
    int value;
    struct node* next;
};
typedef struct node* NODE;
NODE getnode() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    return ptr;
}

NODE insert_stack(NODE first, int item) {
    NODE new = getnode();
    if (new == NULL) return first;
    new->value = item;
    new->next = first;
    return new;
}
NODE del(NODE first) {
    if (first == NULL) {
        printf("Linked List is empty\n");
        return NULL;
    }
    NODE temp = first;
    first = first->next;
    free(temp);
    return first;
}
NODE delete_end(NODE first) {
    if (first == NULL) {
        printf("Linked List empty\n");
        return NULL;
    }
    if (first->next == NULL) {
        free(first);
        return NULL;
    }
    NODE last = first, prev = NULL;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
    return first;
}

NODE enqueue(NODE first, int item) {
    NODE new = getnode();
    if (new == NULL) return first;
    new->value = item;
    new->next = NULL;
    if (first == NULL) {
        return new;
    }
    NODE last = first;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new;
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("Linked List empty\n");
        return;
    }
    NODE temp = first;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch, ele, pos;
    NODE head = NULL;
    while (1) {
        printf("1.Push \n2. Pop \n3. Enqueue\n4. Dequeue\n5.Display");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element :");
                scanf("%d",&ele);
                head=insert_stack(head,ele);
                break;
            case 2:
                head=del(head);
                break;
            case 3:
                printf("Enter element :");
                scanf("%d",&ele);
                head=enqueue(head,ele);
                break;
            case 4:
                head=delete_end(head);
                break;
            case 5:
                display(head);
                break;
            default :printf("Wrong choice");
                    break;
        }

    }
    return 0;
}


