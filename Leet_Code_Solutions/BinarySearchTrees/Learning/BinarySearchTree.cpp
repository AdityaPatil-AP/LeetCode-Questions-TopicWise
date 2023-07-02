#include <bits/stdc++.h>
using namespace std;

// 1. Insert a node into a BST
// A new key is always inserted at the leaf.
// Start searching for a key from the root till a leaf node. 
// Once a leaf is found, the new node is added as the child of the leaf node.

// Struct Information - https://www.geeksforgeeks.org/structures-in-cpp/
struct node{
    int key;
    struct node *left , *right;
}typedef node;

// Function to create a new BST Node.
struct node* newNode(int item){
    node* temp = (node*) malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node with a given key in BST
node* insert(node* root, int key){
    // if the bst is empty, return a newnode
    if(root == NULL){
        return newNode(key);
    }

    // Otherwise, recur down the tree.
    if(key > root->key){
        root->right = insert(root->right, key);
    }
    else if(key < root->key){
        root->left = insert(root->left, key);
    }
    // Return the root pointer
    return root;
}

// Function to do inorder traversal of BST
// Inorder traversal helps us to give the nodes in non-decreasing order(increasing).
// That is we visit the left child, root, and then the right child.
void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Preorder Traversal - Node L R
// It is used to create a copy of the tree.
// It is used to prefix expression on of an expression tree.
void preorder(node* root){
    if(root != NULL){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// PostOrder Traversal - L R Node
// It is helpful in deletion of the Tree. 
// Because we visit the root of every subTree last.
void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

// Level order Traversal - It is the breadth first traversal of the tree.
// We visit all the nodes on the current level first and then move on to the next level.
int height(node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

void printGivenLevel(node* root, int level){
    if(root == NULL){
        return;
    }   
    if(level == 1){
        cout << root->key << " ";
        return;
    }
    else if(level > 1){
        if(root->left) printGivenLevel(root->left, level - 1);
        if(root->right) printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(node *root){
    int h = height(root);
    int i;
    for(i = 1;i <= h;i++){
        printGivenLevel(root, i);
        cout << endl;
    }
}

// Print all leaf nodes. (leaf node - both right and left child are NULL.)
void printLeafNodes(node *root){
    // It is an empty BST.
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cout << root->key << " ";
        return;
    }
    // Recur the left subtree and print the leaf nodes
    printLeafNodes(root->left);
    // Recur the right subtree and print the right nodes.
    printLeafNodes(root->right);
    return;
}

// Print all Non - Leaf Nodes.
void printNonLeafNodes(node *root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    if(root->left != NULL || root->right != NULL) cout << root->key << " ";
    // Recur down the left Subtree
    printNonLeafNodes(root->left);
    // Recur down the right Subtree.
    printNonLeafNodes(root->right);
    return;
}

// Right view of BST;
void rightViewBST(node* root){
    if(!root) return;
    node *temp = root;
    cout << temp->key << " ";
    while(temp->right != NULL){
        temp = temp->right;
        cout << temp->key << " ";
    }
    return;
}

// Minimum Value Node - Smallest value of the BST
node* minValueNode(node* root){
    node* current = root;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}


// Delete a node in BST
node* deleteNode(node* root, int key){
    if(!root) return root;

    if(key < root->key){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }

        // Node with two children - we have to 
        // Get the inorder successor(smallest value in the right Subtree)
        node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Total Nodes in a BST 
int totalNodes(node* root){
    if(!root) return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

node* deleteBST(node* root){
    node* temp = root;
    if(root){
        // Empty the left Subtree
        deleteBST(root->left);
        // Empty the right subtree
        deleteBST(root->right);

        cout << "\nReleased Node is : " << root->key << " ";
        temp = root;
        free(temp);
    }
    return root;
}

int main(){
    // Binary Search Tree.
    node* root = NULL;

    root = insert(root, 4);
    insert(root, 2);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 5);
    insert(root, 7);

    cout << "Inorder Traversal of BST is : " << endl;
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal of BST is : " << endl;
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal of Bst is : " << endl;
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal Of BST are : " << endl;
    printLevelOrder(root);
    cout << endl;

    cout << "Print Given Level of the BST : " << endl;
    printGivenLevel(root, 3);
    cout << endl;

    cout << "Print the leaf nodes of the BST " << endl;
    printLeafNodes(root);
    cout << endl;

    cout << "Print all non-leaf Nodes of the BST " << endl;
    printNonLeafNodes(root);
    cout << endl;

    cout << "Right View of BST : " << endl;
    rightViewBST(root);
    cout << endl;

    cout << "Left View of BST : " << endl;
    // leftViewBST(root);
    // cout << endl;

    cout << "Height of BST : " << height(root) << endl;

    // cout << "Enter a Node to be deleted : " << endl;
    // int key;
    // cin >> key;
    // cout << "Inorder before : ";
    // inorder(root);
    // cout << endl;
    // deleteNode(root, key);
    // cout << "Inorder after : ";
    // inorder(root);
    // cout << endl;

    cout << "Smallest Value of the BST : " << endl;
    cout << minValueNode(root)->key << endl;

    cout << "Total number of nodes in a BST : " << endl;
    cout << totalNodes(root) << endl;

    cout << "Delete A BST : " << endl;
    deleteBST(root);
    cout << endl;

    return 0;
}

// Theory : 

// Binary Search Tree is a Node-Based binary tree data structure which has following properties:
// -> The left Subtree of a node contains only nodes with keys lesser than the node's key.
// -> The right Subtree of a node contains only those nodes whose keys are greater than the node's key.
// -> In this process both right and left Subtree must also be a binary Search Tree.

// There must be no duplicate nodes(BST may have duplicate values with different handling Approaches).
// Handling approach for Duplicate values in the Binary Search are : 

// You have to be consistent either allow duplicates on the left-side or on the right side.
// We can keep a counter and if we found a duplicate we can increment the counter.

// Now we are going to write the operation that are done on the binary Search Tree.