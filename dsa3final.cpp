#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

class BST {
    Node* root;

public:
    BST() : root(nullptr) {}

    void insert();
    void insertLogic(Node*& node, int data);
    void display();
    void traverse(Node* node);
    void search();
    Node* searchLogic(Node* node, int key);
    int getMin();
    int getMinLogic(Node* node);
    int getNodes();
    int getNodesLogic(Node* node);
};

void BST::insert() {
    int data;
    cout << "Enter the value of the node: ";
    cin >> data;

    Node* newNode = new Node(data);

    if (root == nullptr) {
        root = newNode;
    } else {
        insertLogic(root, data);
    }
}

void BST::insertLogic(Node*& node, int data) {
    if (node == nullptr) {
        node = new Node(data);
    } else if (data <= node->val) {
        insertLogic(node->left, data);
    } else {
        insertLogic(node->right, data);
    }
}

void BST::display() {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
    } else {
        cout << "Binary Search Tree" << endl;
        traverse(root);
    }
}

void BST::traverse(Node* node) {
    if (node != nullptr) {
        traverse(node->left);
        cout << node->val << " ";
        traverse(node->right);
    }
}

void BST::search() {
    int key;
    cout << "Enter the value of the node to search: ";
    cin >> key;

    Node* foundNode = searchLogic(root, key);
    if (foundNode != nullptr) {
        cout << "Node found! Address: " << foundNode << endl;
    } else {
        cout << "Node is not present in the tree!" << endl;
    }
}

Node* BST::searchLogic(Node* node, int key) {
    if (node == nullptr || node->val == key) {
        return node;
    } else if (key < node->val) {
        return searchLogic(node->left, key);
    } else {
        return searchLogic(node->right, key);
    }
}

int BST::getMin() {
    return getMinLogic(root);
}

int BST::getMinLogic(Node* node) {
    if (node->left == nullptr) {
        return node->val;
    }
    return getMinLogic(node->left);
}

int BST::getNodes() {
    return getNodesLogic(root);
}

int BST::getNodesLogic(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftPath = getNodesLogic(node->left);
    int rightPath = getNodesLogic(node->right);
    return max(leftPath, rightPath) + 1;
}

int main() {
    BST tree;
    int option;

    while (true) {
        cout << "--------- MENU ---------" << endl;
        cout << "1. Insert new node" << endl;
        cout << "2. Find the number of nodes in the longest path from the root" << endl;
        cout << "3. Find the minimum data value in the tree" << endl;
        cout << "4. Search for a value" << endl;
        cout << "5. Display the binary search tree" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                tree.insert();
                break;
            case 2:
                cout << "Number of nodes in the longest path from the root: " << tree.getNodes() << endl;
                break;
            case 3:
                cout << "Minimum value in the tree: " << tree.getMin() << endl;
                break;
            case 4:
                tree.search();
                break;
            case 5:
                tree.display();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    }
}

/*




Certainly! Here's a step-by-step explanation of the implementation and the concepts used in the code:

The code begins by including the necessary header files and defining the required classes and member functions.

The Node class represents a node in the binary search tree. It contains an integer value (val) and pointers to the left and right child nodes (left and right).

The BST class represents the binary search tree. It has a private member variable root that points to the root node of the tree.

The insert function allows the user to insert a new node into the binary search tree. It prompts the user to enter the value of the node and creates a new node with the given value. If the tree is empty, the new node becomes the root. Otherwise, the insertLogic function is called to recursively find the appropriate position to insert the node based on the binary search tree property.

The insertLogic function recursively traverses the tree to find the appropriate position to insert the new node. It compares the value of the new node with the current node and moves left or right accordingly until it finds an empty spot to insert the node.

The display function prints the binary search tree in an in-order traversal fashion. It calls the traverse function to perform the in-order traversal recursively.

The traverse function performs an in-order traversal of the binary search tree. It recursively visits the left subtree, prints the value of the current node, and then recursively visits the right subtree.

The search function allows the user to search for a specific value in the binary search tree. It prompts the user to enter the value to search for and calls the searchLogic function to recursively search for the value in the tree.

The searchLogic function performs a recursive search in the binary search tree. It compares the value being searched with the current node's value and recursively moves left or right until it finds the node with the desired value. If the value is found, it returns the node; otherwise, it returns nullptr.

The getMin function returns the minimum value in the binary search tree by calling the getMinLogic function. It handles the case when the tree is empty.

The getMinLogic function recursively finds the minimum value in the binary search tree by traversing the left subtree until it reaches the leaf node with the smallest value.

The getNodes function returns the number of nodes in the longest path from the root by calling the getNodesLogic function. It handles the case when the tree is empty.

The getNodesLogic function recursively calculates the number of nodes in the longest path from the root. It computes the lengths of the left and right paths recursively and returns the maximum length plus one.

In the main function, an instance of the BST class is created, and a menu-driven interface is provided to interact with the binary search tree. The user can choose options to insert a new node, find the number of nodes in the longest path from the root, find the minimum value in the tree, search for a value, display the tree, or exit the program. The user's choice is processed in a loop until the user chooses to exit.

The concepts used in this code include:

Classes and objects: The code uses classes to define the Node and BST data structures. Objects of these classes are created to represent nodes and the binary search tree.

Pointers: Pointers are used to maintain the connections between nodes in the binary search tree. They allow traversal and manipulation of the tree structure

*/