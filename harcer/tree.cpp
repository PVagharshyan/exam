#include <iostream>
#include <vector>

struct Node {
    char data {};
    Node* left {};
    Node* right {};
};

int getHeight(Node* root) {
    if (root == nullptr) return 0;
    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

bool AVL_or_not(Node* root) {
    if (root == nullptr) return true;
    return (getHeight(root->left) - getHeight(root->right)) == 0 && AVL_or_not(root->left) && AVL_or_not(root->right);
}

void levelTaravers (Node* root, int level, std::vector<int>& result) {
    if (root == nullptr) return;

    if (level == 1) {
        result.push_back(root->data);
    }
    else if (level > 1) {
        levelTaravers(root->left, level - 1, result);
        levelTaravers(root->right, level - 1, result);
    }
} 

std::vector<std::vector<int>> levelOrderTravers(Node* root) {
    std::vector<std::vector<int>> result {};
    int height = getHeight(root);

    for (int i = 1; i <= height; ++i) {
        std::vector<int> current_level_elements = {};
        levelTaravers(root, i, current_level_elements);
        result.push_back(current_level_elements);
    }
    return result;
}

std::vector<std::vector<int>> levelOrderReverse(Node* root) {
    std::vector<std::vector<int>> result;

    int height = getHeight(root);

    for (int i = height; i > 0; --i) {
        std::vector<int> current_level_elements = {};
        levelTaravers(root, i, current_level_elements);
        result.push_back(current_level_elements);
    }

    return result;
}

Node* create_tree(char* pre, char* in, int pre_s, int in_s, int count) {
    if (count == 0) return nullptr;

    int i;
    for (i = 0; i < count; ++i) {
        if (pre[pre_s] == in[in_s + i]) {
            break;
        }
    }
    Node* new_node = new Node { pre[pre_s] };

    new_node->left = create_tree(pre, in, pre_s + 1, in_s, i);
    new_node->right = create_tree(pre, in, pre_s + 1 + i, in_s + i + 1, count - i - 1);
    return new_node;
}

bool from_the_root_to_the_top(Node* root, int key, std::vector<int>& array) {
    if (root == nullptr) return false;

    if (root->data == key) {
        array.push_back(root->data);
        return true;
    }
    if (from_the_root_to_the_top(root->left, key, array) || from_the_root_to_the_top(root->left, key, array)) {
        array.push_back(root->data);
        return true;
    }

    return false;
}

int main() {
    Node* D = new Node {'D'};
    Node* C = new Node {'C'};
    Node* B = new Node {'B'};
    Node* root = new Node{ 'A', B, C};
    std::vector<std::vector<int>> result_levels = levelOrderTravers(root);

    for (auto& item : result_levels) {
        for (auto& i : item) {
            std::cout << (char)i << " ";
        }
        std::cout << std::endl;
    }

    result_levels = levelOrderReverse(root);

    for (auto& item : result_levels) {
        for (auto& i : item) {
            std::cout << (char)i << " ";
        }
        std::cout << std::endl;
    }

    char in[] = {'1', '2', '3', '4'};
    char pre[] = {'3', '2', '1', '4'};
    Node* new_root = create_tree(pre, in, 0, 0, 4);

    std::vector<std::vector<int>> v = levelOrderTravers(new_root);
    for (auto& item : v) {
        for (auto& i : item){
            std::cout << (char)i << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "------" << std::endl;

    std::vector<int> t {};
    from_the_root_to_the_top(new_root, '1', t);
    for (auto& item : t) {
        std::cout << (char)item << std::endl;
    }

    return 0;
}