#include <stdio.h>
#include <stdlib.h>


 struct BST {
    int data;
    struct BST* left;
    struct BST* right;
} ;
typedef struct BST *NODE;



NODE create() {
    NODE temp = (NODE)malloc(sizeof(struct BST));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}


NODE insert(NODE root, NODE temp) {
    if (root == NULL) {
        return temp;
    } else if (temp->data < root->data) {
        root->left = insert(root->left, temp);
    } else if (temp->data > root->data) {
        root->right = insert(root->right, temp);
    }
    return root;
}


void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    NODE root = NULL;
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                NODE temp = create();
                root = insert(root, temp);
                break;
            }
            case 2:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

