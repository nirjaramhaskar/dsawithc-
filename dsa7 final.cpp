#include <iostream>
#include <stack>
#include <cctype>

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char data) : data(data), left(nullptr), right(nullptr) {}
};

class Tree {
    Node* top;

public:
    void expression(const std::string& prefix);
    void display(Node* root);
    void non_rec_postorder(Node* top);
    void del(Node* node);
};

void Tree::expression(const std::string& prefix) {
    std::stack<Node*> stack;
    Node* t1;
    Node* t2;

    for (int i = prefix.length() - 1; i >= 0; --i) {
        top = new Node(prefix[i]);
        if (std::isalpha(prefix[i])) {
            stack.push(top);
        } else if (prefix[i] == '+' || prefix[i] == '*' || prefix[i] == '-' || prefix[i] == '/') {
            t2 = stack.top();
            stack.pop();
            t1 = stack.top();
            stack.pop();
            top->left = t2;
            top->right = t1;
            stack.push(top);
        }
    }
    top = stack.top();
}

void Tree::display(Node* root) {
    if (root != nullptr) {
        std::cout << root->data;
        display(root->left);
        display(root->right);
    }
}

void Tree::non_rec_postorder(Node* top) {
    std::stack<Node*> stack1;
    std::stack<Node*> stack2;
    Node* T = top;

    stack1.push(T);
    while (!stack1.empty()) {
        T = stack1.top();
        stack1.pop();
        stack2.push(T);

        if (T->left != nullptr) {
            stack1.push(T->left);
        }
        if (T->right != nullptr) {
            stack1.push(T->right);
        }
    }

    while (!stack2.empty()) {
        top = stack2.top();
        stack2.pop();
        std::cout << top->data;
    }
}

void Tree::del(Node* node) {
    if (node == nullptr) {
        return;
    }

    del(node->left);
    del(node->right);
    std::cout << "\nDeleting node: " << node->data << std::endl;
    delete node;
}

int main() {
    std::string expr;
    Tree t;

    std::cout << "Enter prefix Expression: ";
    std::cin >> expr;

    t.expression(expr);
    t.non_rec_postorder(t.top);
    t.del(t.top);

    return 0;
}