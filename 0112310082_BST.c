#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct BinaryTreeNode {
    int key;
    struct BinaryTreeNode *left, *right;
};

// Function to create a new node with a given value
struct BinaryTreeNode* newNodeCreate(int value) {
    struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}



// Function to insert a node with a specific value in the tree
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value) {
    if (node == NULL) {
        return newNodeCreate(value);
    }
    if (value < node->key) {
        node->left = insertNode(node->left, value);
    } else if (value > node->key) {
        node->right = insertNode(node->right, value);
    }
    return node;
}
// Function to search for a node with a specific key in the tree
struct BinaryTreeNode* searchNode(struct BinaryTreeNode* root, int target) {
    if (root == NULL) {
        printf("%d not found\n", target);
        return NULL;
    }
    if (root->key == target) {
        printf("%d found\n", target);
        return root;
    }
    if (root->key < target) {
        return searchNode(root->right, target);
    }
    return searchNode(root->left, target);
}

// Function to perform in-order traversal
void inOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

// Function to perform pre-order traversal
void preOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to perform post-order traversal
void postOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

// Function to find the minimum value
struct BinaryTreeNode* findMin(struct BinaryTreeNode* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left != NULL) {
        return findMin(root->left);
    }
    return root;
}

// Function to find the maximum value
struct BinaryTreeNode* findMax(struct BinaryTreeNode* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->right != NULL) {
        return findMax(root->right);
    }
    return root;
}

// Function to delete a node from the tree
struct BinaryTreeNode* deleteNode(struct BinaryTreeNode* root, int x) {
    if (root == NULL) {
        printf("Value %d not found in the tree\n", x);
        return NULL;
    }

    if (x > root->key) {
        root->right = deleteNode(root->right, x);
    } else if (x < root->key) {
        root->left = deleteNode(root->left, x);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            struct BinaryTreeNode* temp = (root->left == NULL) ? root->right : root->left;
            free(root);
            return temp;
        } else {
            struct BinaryTreeNode* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}



// Function to find the second minimum value
struct BinaryTreeNode* findSecondMin(struct BinaryTreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return NULL;  
    }

    struct BinaryTreeNode* parent = NULL;
    struct BinaryTreeNode* current = root;

    while (current->left != NULL) {
        parent = current;
        current = current->left;
    }

    if (current->right != NULL) {
        return findMin(current->right);
    }

    return parent;
}



// Function to find the second maximum value
struct BinaryTreeNode* findSecondMax(struct BinaryTreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return NULL;  
    }

    struct BinaryTreeNode* parent=NULL;
    struct BinaryTreeNode* current=root;

    while (current->right != NULL) {
        parent = current;
        current = current->right;
    }

    if (current->left != NULL) {
        return findMax(current->left);
    }

    return parent;
}



// Function to update a node's value
struct BinaryTreeNode* updateNode(struct BinaryTreeNode* root, int oldValue, int newValue) {
    if (searchNode(root, oldValue) != NULL) {
        root = deleteNode(root, oldValue);
        root = insertNode(root, newValue);
    }
    return root;
}

int main() {
    struct BinaryTreeNode* root=NULL;
    int choice, value, oldValue, newValue;

    while (1) {
        printf("\nMenu:\n");
        printf("1.Insert\n");
        printf("2.In-order Traversal\n");
        printf("3.Pre-order Traversal\n");
        printf("4.Post-order Traversal\n");
        printf("5.Search\n");
        printf("6.Find Minimum\n");
        printf("7.Find Maximum\n");
        printf("8.Update\n");
        printf("9.Delete\n");
        printf("10.Find Second Minimum\n");
        printf("11.Find Second Maximum\n");
        printf("12.Exit\n");
        printf("Enter your choice from the Menu: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("%d is inserted", value);
                root = insertNode(root, value);
                break;
            case 2:
                if (root != NULL) {
                    printf("In-order Traversal: ");
                    inOrder(root);
                    printf("\n");
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 3:
                if (root !=NULL) {
                    printf("Pre-order Traversal: ");
                    preOrder(root);
                    printf("\n");
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 4:
                if (root !=NULL) {
                    printf("Post-order Traversal: ");
                    postOrder(root);
                    printf("\n");
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d",&value);
                searchNode(root, value);
                break;
            case 6:
                if (root !=NULL) {
                    struct BinaryTreeNode* minNode = findMin(root);
                    if (minNode != NULL) {
                        printf("Minimum value: %d\n",minNode->key);
                    }
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 7:
                if (root != NULL) {
                    struct BinaryTreeNode* maxNode =findMax(root);
                    if (maxNode != NULL) {
                        printf("Maximum value: %d\n",maxNode->key);
                    }
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 8:
                if (root !=NULL) {
                    printf("Enter value to update: ");
                    scanf("%d",&oldValue);
                    printf("Enter new value: ");
                    scanf("%d",&newValue);
                    root = updateNode(root,oldValue,newValue);
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 9:
                if (root != NULL) {
                    printf("Enter value to delete: ");
                    scanf("%d", &value);
                    root = deleteNode(root, value);
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 10:
             if (root != NULL) {
                    struct BinaryTreeNode* secondMinNode = findSecondMin(root);
                    if (secondMinNode != NULL) {
                        printf("Second Minimum value: %d\n", secondMinNode->key);
                    } else {
                        printf("Not enough elements for second minimum\n");
                    }
                } else {
                    printf("Tree is empty\n");
                }
                break;

            case 11:

                if (root != NULL) {
                    struct BinaryTreeNode* secondMaxNode = findSecondMax(root);
                    if (secondMaxNode != NULL) {
                        printf("Second Maximum value: %d\n", secondMaxNode->key);
                    } else {
                        printf("Not enough elements for second maximum\n");
                    }
                } else {
                    printf("Tree is empty\n");
                }
                break;

            case 12:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}