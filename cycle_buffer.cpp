#include <iostream>
#include <vector>

class queue {
    int* buffer {};
    int capacity {};
    int start {};
    int end {};
public:
    queue() : capacity{5} {
        buffer = new int[capacity];
    }
    void reset(int new_size) {
        int counter = start;
        int i = 0;
        start = 0;
        int* tmp = new int[new_size];
        while (counter < capacity) {
            tmp[i++] = buffer[counter % capacity];
            ++counter;
        }
        delete [] buffer;
        buffer = tmp;
        capacity = new_size;
        end = i;
    }
    void add_element(int value) {
        buffer[end++] = value;
        end %= capacity;
        if (end == start) {
            reset(capacity*2);
        }
    }
    void delete_element() {
        start++;
        start %= capacity;
    }
    void display() const {
        int counter = start;
        while (counter != end) {
            std::cout << buffer[counter % capacity] << std::endl;
            ++counter;
        }
    }
};

int main() {
    queue q;
    q.add_element(1);
    q.add_element(2);
    q.add_element(3);
    q.add_element(4);
    q.delete_element();
    q.display();
    return 0;
}