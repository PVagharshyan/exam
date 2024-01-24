#include <iostream>
#include <algorithm>
#include <vector>

class BST {
    struct Node {
        int data {};
        Node* left {};
        Node* right {};
    };
    Node* m_root {};
    bool search(Node* root, int data) const {
        if (root == nullptr) return false;
        if (root->data > data) return search(root->left, data);
        else if (root->data < data) return search(root->right, data);
        return true;
    }
    Node* getMin(Node* root) const {
        if (root->left == nullptr) return root;
        return getMin(root->left);
    }
    Node* getMax(Node* root) const {
        if (root->right == nullptr) return root;
        return getMax(root->right);
    }
    int getHeight(Node* root) const {
        if (root == nullptr) return 0;
        return std::max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    Node* getPredecesser(Node* root) const {
        if (root == nullptr) throw std::runtime_error("error..");
        if (root->left) return getMax(root->left);
        else {
            Node* pred = nullptr;
            Node* acs = m_root;
            while (acs != root) {
                if (acs->data < root->data) {
                    pred = acs;
                    acs = acs->right;
                }
                else {
                    acs = acs->left;
                }
            }
            return pred;
        }
    }
    Node* getSuccecessor(Node* root) const {
        if (root == nullptr) throw std::runtime_error("Error...");
        if (root->right) return getMin(root);
        else {
            Node* pred = nullptr;
            Node* acs = m_root;
            while (acs != root) {
                if (acs->data < root->data) {
                    acs = acs->right; 
                }
                else {
                    pred = acs;
                    acs = acs->left;
                }
            }
            return pred;
        }
    }
    Node* insert(Node* root, int data) {
        if (root == nullptr) return new Node { data };
        if (root->data < data) {
            root->right = insert(root->right, data);
        }
        else {
            root->left = insert(root->left, data);
        }

        return root;
    }
    Node* delete_element(Node* root, int data) {
        if (root == nullptr) return nullptr;
        if (root->data < data) {
            root->right = delete_element(root->right, data);
        }
        else if (root->data > data) {
            root->left = delete_element(root->left, data);
        }
        else {
            if (!root->left) {
                Node* tmp = root->right;
                delete root;
                return tmp;
            }
            if (!root->right) {
                Node* tmp = root->left;
                delete root;
                return tmp; 
            }
            Node* tmp = getMin(root->right);
            root->data = tmp->data;
            root->right = delete_element(root->right, tmp->data);
        }
        return root;
    }
    std::vector<int> inorder(Node* root) const {
        if (root == nullptr) return {};
        std::vector<int> result{};
        std::vector<int> left = inorder(root->left);
        std::vector<int> med { root->data };
        std::vector<int> right = inorder(root->right);
        for (auto& item : left) {
            result.push_back(item);
        }
        result.push_back(med[0]);
        for (auto& item : right) {
            result.push_back(item);
        }
        return result;
    }
    std::vector<int> perorder(Node* root) const {
        if (root == nullptr) return {};
        std::vector<int> result{};
        std::vector<int> left = perorder(root->left);
        std::vector<int> med { root->data };
        std::vector<int> right = perorder(root->right);
        result.push_back(med[0]);
        for (auto& item : left) {
            result.push_back(item);
        }
        for (auto& item : right) {
            result.push_back(item);
        }
        return result;
    }
    int getBF(Node* root) const {
        if (root == nullptr) return 0;
        return getHeight(root->left) - getHeight(root->right);
    }

public: 
    bool search(int data) const {
        //O(n) time complexity
        //O(n) space
        return search(m_root, data);
    }
    bool search_iterativ(int data) const {
        //O(n) time complexity
        //O(1) space
        if (m_root == nullptr) return false;
        Node* current_node = m_root;
        while(current_node) {
            if (current_node->data == data) {
                return true;
            }
            else if (current_node->data > data) {
                current_node = current_node->left;
            }
            else {
                current_node = current_node->right;
            }
        }
        return false;
    }
    Node* getMin() const {
        //O(n) time complexity
        //O(n) space
        return getMin(m_root);
    } 
    Node* getMax() const {
        //O(n) time complexity
        //O(n) space
        return getMax(m_root);
    }
    int getMin_iterativ() const {
        //O(n) time complexity
        //O(1) space
        Node* current_node = m_root;

        while(current_node->left) {
            current_node = current_node->left;
        } 
        return current_node->data;
    }
    int getMax_iterativ() const {
        //O(n) time complexity
        //O(1) space
        Node* current_node = m_root;

        while(current_node->right) {
            current_node = current_node->right;
        }
        return current_node->data;
    }
    int getHeight() const {
        return getHeight(m_root);
    }
    void insert(int data) {
        m_root = insert(m_root, data);
    }
    void delete_element(int data) {
        m_root = delete_element(m_root, data);
    }
    std::vector<int> perorder() const {
        return perorder(m_root);
    }
    std::vector<int> inorder() const {
        return inorder(m_root);
    }
    std::vector<int> postorder() const {
        return {};
    }
    void display() const {
        std::cout << "inorder: " << std::endl;
        for (auto& item : inorder()) {
            std::cout << item << " ";
        }
        std::cout << std::endl << std::endl;
        std::cout << "preorder: " << std::endl;
        for (auto& item : perorder()) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
        std::cout << "Oder: " << std::endl;
        std::cout << getPredecesser(getPredecesser(m_root))->data << std::endl;
        std::cout << getSuccecessor(getPredecesser(m_root))->data << std::endl;
        std::cout << "balans fuctor: " << std::endl;
        std::cout << getBF(m_root) << std::endl;
        std::cout << ":::::" << std::endl;
    }
};

int main() {
    BST bst;
    bst.insert(6);
    bst.insert(3);
    bst.insert(5);
    bst.insert(4);
    bst.display();
    std::cout << bst.getMax_iterativ() << std::endl;
    std::cout << bst.getMin_iterativ() << std::endl;
    std::cout << bst.search_iterativ(1) << std::endl;
    return 0;
}