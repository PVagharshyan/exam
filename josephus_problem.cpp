#include <iostream>

struct Node {
    int data {};
    Node* next {};
};

void print(Node* start) {
    Node* current_node = start;
    while(current_node) {
        std::cout << current_node->data << " ";
        current_node = current_node->next;
    }
}

int W(int count_s) {
    Node* first_s = new Node{1};
    Node* current_node = first_s;

    for (int i = 2;i <= count_s; ++i) {
        current_node->next = new Node{i};
        current_node = current_node->next;
    }

    current_node->next = first_s;

    current_node = first_s;

    while (current_node->next != current_node) {
        Node* tmp = current_node->next;
        current_node->next = tmp->next;
        current_node = tmp->next;
        //std::cout << "kill: " << tmp->data << std::endl;
        delete tmp;
    }

    return current_node->data;
}

int main() {
    // only count soldiers imput and 1 output 
    // int count_s;
    // std::cout << "input: ";
    // std::cin >> count_s;
    
    int count;
    std::cin >> count;

    for (int i = 1; i <= count; ++i) {
        std::cout << i << "->" << W(i) << std::endl;
    }
    
    return 0;
}