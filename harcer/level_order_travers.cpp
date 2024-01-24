#include <iostream>
#include <queue>
#include <vector>

struct Node {
    int data {};
    Node* left {};
    Node* right {};
};

std::vector<std::vector<int>> level_order_tarvers(Node* root) {
    std::vector<std::vector<int>> result;
    std::queue<std::pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        std::pair<Node*, int> current_node = q.front();
        q.pop();
        int level = current_node.second;
        Node* node = current_node.first;

        if (result.size() <= level) {
            result.push_back({});
        }

        result[result.size() - 1].push_back(node->data);
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
    return result;
}


int main() {
    Node* C = new Node{13};
    Node* B = new Node{12};
    Node* A = new Node{11, C};
    Node* root = new Node{10, A, B};
    std::vector<std::vector<int>> levelorder = level_order_tarvers(root);
    for (int i = 0; i < levelorder.size(); ++i) {
        for (int j = 0; j < levelorder[i].size(); ++j) {
            std::cout << levelorder[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int weight_tree = levelorder[0].size();

    for (auto& item : levelorder) {
        if (weight_tree < item.size()) {
            weight_tree = item.size();
        }
    }
    std::cout << "weight of tree: " << std::endl;
    std::cout << weight_tree << std::endl;

    return 0;
}