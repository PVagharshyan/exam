#include <iostream>
#include <vector>

struct Node {
    int data{};
    int left {-1};
    int right {-1};
};

bool is_search_tree(const std::vector<Node>& arr, int root = 0) {
    if (root == -1) return true;
    bool left = is_search_tree(arr, arr[root].left);
    bool right = is_search_tree(arr, arr[root].right);
    bool current_root_l = true, current_root_r = true;
    if (arr[root].left != -1) current_root_l = arr[arr[root].left].data < arr[root].data;
    if (arr[root].right != -1) current_root_r = arr[arr[root].right].data >= arr[root].data;
    bool current_root = current_root_l && current_root_r; 
    return left && right && current_root;
}


int main() {
    Node* D = new Node {4};
    Node* C = new Node {8, 3};
    Node* B = new Node {15};
    Node* A = new Node {10, 2, 1};

    std::vector<Node> tree = {*A, *B, *C, *D};
    std::cout << is_search_tree(tree) << std::endl;
    return 0;
}