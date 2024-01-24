#include <iostream>
#include <algorithm>
#include <vector>

class priority_queue {
public:
    void push(int value) {
        data.push_back(value);
        int current_index = size;
        ++size;
        while (current_index != 0 && value > data[(current_index-1)/2]) {
            std::swap(data[current_index], data[(current_index-1)/2]);
            current_index = (current_index - 1)/2;
        }
    }
    void pop() {
        std::swap(data[0], data[size - 1]);
        data.pop_back();
        --size;
        int current_index = 0;
        while (2*current_index + 1 < size && 2*current_index + 2 < size && (data[current_index] < data[2*current_index + 1] || data[current_index] < data[2*current_index + 2])){
            if (data[current_index] < data[2*current_index + 1]){
                std::swap(data[current_index], data[2*current_index + 1]);
                current_index = 2*current_index + 1;
            }
            else {
                std::swap(data[current_index], data[2*current_index + 2]);
                current_index = 2*current_index + 2;
            }
        }
    }
    void print() const {
        if (size == 0) std::cout << "is empty!" << std::endl;
        for (auto item : data) {
            std::cout << item << " ";
        }
    }
private:
    std::vector<int> data {};
    int size {};
};

int main() {
    priority_queue q;
    q.push(10);
    q.push(20);
    q.push(15);
    q.push(30);
    q.print();
    q.pop();
    std::cout << std::endl;
    q.print();
    q.pop();
    std::cout << std::endl;
    q.print();
    q.pop();
    std::cout << std::endl;
    q.print();
    q.pop();
    std::cout << std::endl;
    q.print();



    return 0;
}