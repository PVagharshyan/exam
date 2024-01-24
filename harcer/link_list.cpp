#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

struct Node {
    int data {};
    Node* next {};
};

void unique(Node* start) {
    Node* current = start;
    Node* prev = nullptr;

    std::unordered_set<int> unique_elements;

    while (current != nullptr) {
        if (unique_elements.find(current->data) != unique_elements.end()) {
            Node* tmp = current->next;
            delete current;
            prev->next = tmp;
            current = tmp;
        }
        else {
            unique_elements.insert(current->data);
            prev = current;
            current = current -> next;
        }
    }
}

void add_new_element(Node* start, int data) {
    Node* prev = nullptr;
    Node* current = start;

    while (current->data < data) {
        prev = current;
        current = current->next;
    }

    prev->next = new Node {data};
    prev->next->next = current;
}

void sort_list(Node* start) {
    if (start == nullptr) return;
    Node* current = start->next;
    Node* prev = start;
    while (current != nullptr) {
        if (current->data < prev->data) {
            std::swap(current->data, prev->data);
        }
        prev = current;
        current = current->next;
    }   
}

void reverse_linked_list(Node*& start) {
    Node* prev = nullptr;
    Node* current = start;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    start = prev;
}

bool compair_lex(Node* start_1, Node* start_2) {
    while(start_1 != nullptr && start_2 != nullptr) {
        if (start_1->data < start_2->data) {
            return true;
        }
        else if (start_1->data > start_2->data) {
            return false;
        }

        start_1 = start_1->next;
        start_2 = start_2->next;
    }

    return (start_1 == nullptr && start_2 != nullptr);
}

void remove_vol(Node*& start) {
    Node* current = start;
    Node* prev = nullptr;

    std::vector<int> vowel = {(char)15, (char)14, 'i', 'o', 'u'};

    while (current != nullptr) {
        bool flag = false;
        for (auto& item : vowel) {
            if (item == current->data) {
                flag = true;
            }
        }
        if (flag) {
            Node* tmp = current->next;
            delete current;
            if (prev != nullptr)
                prev->next = tmp;
            else {
                start = tmp;
            }
            current = tmp;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

struct newNode {
    int data {};
    int next {-1};
};

void bubble_sort_list_array(std::vector<newNode>& array, int start = 0) {
    
    int current_node = start;

    while (array[current_node].next != -1) {
        int inner_node = array[current_node].next;
        while (inner_node != -1) {
            if (array[inner_node].data < array[current_node].data) {
                std::swap(array[inner_node].data, array[current_node].data);
            }
            inner_node = array[inner_node].next;
        }
        current_node = array[current_node].next;
    }
}

void print(const std::vector<newNode>& array, int start = 0) {
    int current_node = start;

    while (current_node != -1) {
        std::cout << array[current_node].data << " ";
        current_node = array[current_node].next;
    }
    std::cout << std::endl;
}


int main() {
    Node* D = new Node {15};
    Node* C = new Node {11, D};
    Node* B = new Node {11, C};
    Node* A = new Node {10, B};
    Node* start = new Node {10, A};

    unique(start);
    
    add_new_element(start, 13);
    add_new_element(start, 14);

    Node* current = start;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
    sort_list(start);
    std::cout << std::endl;
    current = start;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }

    reverse_linked_list(start);

    std::cout << std::endl;
    current = start;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }

    remove_vol(start);

    std::cout << std::endl;
    current = start;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }

    std::vector<newNode> arr = { newNode{2, 1}, newNode{1, 2}, newNode{3, -1} };

    bubble_sort_list_array(arr);
    print(arr);

    current = start;
    while (current != nullptr) {
        Node* tmp = current->next;
        delete current;
        current = tmp;
    }    
    
    return 0;
}
