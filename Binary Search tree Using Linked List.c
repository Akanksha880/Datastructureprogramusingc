#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        return createNode(data);
    }
    // Otherwise, do recursive insertion
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a key in BST
struct Node* search(struct Node* root, int key) {
    // Base case: root is null or key is present at the root
    if (root == NULL || root->data == key) {
        return root;
    }
    // Key is greater than root's data, search in the right subtree
    if (root->data < key) {
        return search(root->right, key);
    }
    // Key is smaller than root's data, search in the left subtree
    return search(root->left, key);
}

// Function to perform inorder traversal of BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the key to be searched: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("Key found in the BST\n");
                } else {
                    printf("Key not found in the BST\n");
                }
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
