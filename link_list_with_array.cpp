#include <iostream>

struct Node {
    int data {};
    int next { -1 };
    bool val { false };
};

class link_list {
    Node* ptr {};
    int start { -1 };
    int capacity { 5 };
public:
    link_list() {
        ptr = new Node[capacity];
    } 
    void reset() {
        bool full = true;

        for (int i = 0; i < capacity; ++i) {
            if (ptr[i].val == false) {
                full = false;
            }
        }

        if (full) {
            Node* tmp = new Node[capacity*2];
            for (int i = 0; i < capacity; ++i) {
                tmp[i] = ptr[i];
            }
            capacity *= 2;
            delete [] ptr;
            ptr = tmp;
            tmp = nullptr;
        }
    }
    void push_back(int data) {
        if (start == -1) {
            ptr[0].data = data;
            ptr[0].val = true;
            start = 0;
            return;
        }

        reset();

        int current_node = start;
        while (ptr[current_node].next != -1) {
            current_node = ptr[current_node].next;
        }
        
        for (int i = 0;i < capacity; ++i) {
            if (ptr[i].val == false) {
                ptr[current_node].next = i;
                ptr[i].data = data;
                ptr[i].val = true;
                break;
            }
        }
    } 
    void push_front(int data) {
        if (start == -1) {
            ptr[0].data = data;
            ptr[0].val = true;
            start = 0;
            return;
        }

        reset();

        for (int i = 0;i < capacity; ++i) {
            if (ptr[i].val == false) {
                ptr[i].next = start;
                ptr[i].data = data;
                ptr[i].val = true;
                start = i;
                break;
            }
        }
    }
    void display() const {
        int current_node = start;
        while (ptr[current_node].next != -1) {
            std::cout << ptr[current_node].data << " ";
            current_node = ptr[current_node].next;
        }
        std::cout << ptr[current_node].data << std::endl;
    }
    void display_buffer() const {
        for (int i = 0; i < capacity; ++i) {
            std::cout << "data: " << ptr[i].data << ", next: " << ptr[i].next << ", val: " << ptr[i].val << std::endl;
        }
    }
};

int main() {
    link_list l;
    l.push_back(10);
    l.push_back(2);
    l.push_back(6);
    l.push_back(18);
    l.push_back(18);
    l.push_back(18);
    l.push_front(11);
    l.display();
    return 0;
}