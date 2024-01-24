#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

class AVL {
    struct Node {
        int data {};
        Node* left {};
        Node* right {};
    };
    Node* m_root {};

    Node* rightRotate(Node* root) {
        Node* new_root = root->left;
        Node* sep = new_root->right;
        new_root->right = root;
        root->left = sep;
        return new_root;
    }

    Node* leftRotate(Node* root) {
        Node* new_root = root->right;
        Node* sep = new_root->left;
        new_root->left = root;
        root->right = sep;
        return new_root;
    }

    int getHeight(Node* root) {
        if (root == nullptr) return 0;
        return std::max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    
    int BF(Node* root) {
        if (root == nullptr) return 0;
        return getHeight(root->left) - getHeight(root->right);
    }

    Node* insert(Node* root, int data) {
        if (root == nullptr) return new Node { data };

        if (root->data < data) {
            root->right = insert(root->right, data);
        } else {
            root->left = insert(root->left, data);
        }

        int balance = BF(root);

        if (balance == 2) {
            if (data < root->left->data) {
                return rightRotate(root);
            } else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        } else if (balance == -2) {
            if (data > root->right->data) {
                return leftRotate(root);
            } else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }

        return root;
    }

    Node* getMin(Node* root) {
        if (root == nullptr) return root;
        return getMin(root->left);
    }

    Node* delete_element(Node* root, int data) {
        if (root == nullptr) return nullptr; // Fixed this line

        if (root->data < data) {
            root->right = delete_element(root->right, data);
        } 
        else if (root->data > data) {
            root->left = delete_element(root->left, data);
        }
        else {
            if (!root->right) {
                Node* tmp = root->left;
                delete root;
                return tmp;
            }
            if (!root->left) {
                Node* tmp = root->right;
                delete root;
                return tmp;
            }
            Node* tmp = getMin(root->right);
            root->data = tmp->data;
            root->right = delete_element(root->right, tmp->data);
        }

        int balance = BF(root);

        if (balance == 2) {
            if (BF(root->left) == 0 || BF(root->left) == 1) {
                return rightRotate(root);
            }
            else {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if (balance == -2) {
            if (BF(root->right) == 0 || BF(root->right) == -1) {
                return leftRotate(root);
            }
            else {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }
    void display_inorder(Node* root) {
        if (root == nullptr) return;
        display_inorder(root->left);
        std::cout << root->data << " ";
        display_inorder(root->right);
    }
    void display_levelorder(Node* root) {
        std::queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* tmp = q.front();

            q.pop();
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
            std::cout << tmp->data << " ";
        }
    }
public:
    void insert(int data) {
        m_root = insert(m_root, data);
    }
    void delete_element(int data) {
        m_root = delete_element(m_root, data);
    }
    void display() {
        display_inorder(m_root);
        std::cout << std::endl;
        std::cout << "level_order: " << std::endl;
        display_levelorder(m_root);
        std::cout << std::endl;
    }
};

int main() {
    AVL avl;
    avl.insert(1);
    avl.insert(2);
    avl.insert(3);
    avl.insert(4);
    avl.insert(5);
    avl.display();
    avl.delete_element(1);
    avl.delete_element(5);
    avl.display();
    return 0;
}