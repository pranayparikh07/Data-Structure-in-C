
#include <stdio.h>
#include <stdlib.h>

// Define a node of the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Declare the root pointer globally
struct Node *root = NULL;

// Create a new node with the given value
struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a value into its correct position in the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Traverse the left subtree, root, and right subtree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Traverse the root, left subtree, and right subtree
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Traverse the left subtree, right subtree, and root
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int choice, value;
        printf("\n\n1. Insert Node");
        printf("\n2. In-order Traversal");
        printf("\n3. Pre-order Traversal");
        printf("\n4. Post-order Traversal");
        printf("\n5. Exit");

    // Display the menu repeatedly until the user exits
    while (1) {
    
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform the operation selected by the user
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted successfully.");
                break;

            case 2:
                if (root == NULL)
                    printf("Tree is empty.");
                else {
                    printf("In-order: ");
                    inorder(root);
                }
                break;

            case 3:
                if (root == NULL)
                    printf("Tree is empty.");
                else {
                    printf("Pre-order: ");
                    preorder(root);
                }
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty.");
                else {
                    printf("Post-order: ");
                    postorder(root);
                }
                break;

            case 5:
                // Terminate the program
                exit(0);

            default:
                printf("Invalid choice.");
        }
    }

    return 0;
}
