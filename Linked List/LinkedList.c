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

NODE insert_beg(NODE first, int item) {
    NODE new = getnode();
    if (new == NULL) return first;
    new->value = item;
    new->next = first;
    return new;
}

NODE insert_end(NODE first, int item) {
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

NODE insert_pos(NODE first, int item, int pos) {
    NODE new = getnode();
    if (new == NULL) return first;
    new->value = item;

    if (pos == 1) {
        new->next = first;
        return new;
    }

    NODE prev = NULL, current = first;
    int count = 1;
    while (current != NULL && count < pos) {
        prev = current;
        current = current->next;
        count++;
    }

    if (prev != NULL) {
        prev->next = new;
        new->next = current;
    }

    return first;
}

NODE delete_beg(NODE first) {
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

NODE delete_val(NODE first, int val) {
    if (first == NULL) {
        printf("Linked List is empty\n");
        return NULL;
    }

    NODE prev = NULL, curr = first;
    while (curr != NULL && curr->value != val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Value not found\n");
        return first;
    }

    if (prev == NULL) {

        first = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
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
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at a position\n4. Delete at beginning\n5. Delete at end\n6. Delete a value\n7. Display\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ele);
                head = insert_beg(head, ele);
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", &ele);
                head = insert_end(head, ele);
                break;
            case 3:
                printf("Enter the element and position: ");
                scanf("%d %d", &ele, &pos);
                head = insert_pos(head, ele, pos);
                break;
            case 4:
                head = delete_beg(head);
                break;
            case 5:
                head = delete_end(head);
                break;
            case 6:
                printf("Enter the value to delete: ");
                scanf("%d", &ele);
                head = delete_val(head, ele);
                break;
            case 7:
                display(head);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
