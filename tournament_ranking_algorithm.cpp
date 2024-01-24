#include <iostream>
#include <vector>

class heap {
    std::vector<int> heap_array {};
    void display_array() {
        for (auto& item : heap_array) {
            std::cout << item << " ";
        }
    }
public:
    void insert(int data) {
        heap_array.push_back(data);
        int current_index = heap_array.size() - 1;
        while (current_index != 0 && heap_array[current_index] < heap_array[(current_index-1)/2]) {
            std::swap(heap_array[current_index], heap_array[(current_index-1)/2]);
            current_index = (current_index - 1)/2;
        }
    }
    int delete_element() {
        if (heap_array.size() == 0) throw std::runtime_error("error..");
        int tmp = heap_array[0];
        std::swap(heap_array[0], heap_array[heap_array.size() - 1]);
        heap_array.pop_back();
        int current_index = 0;

        while (true) {
            int left = 2*current_index + 1;
            int right = 2*current_index + 2;

            int min_index = current_index;

            if (left < heap_array.size() && heap_array[current_index] > heap_array[left]) {
                min_index = left;
            }
            if (right < heap_array.size() && heap_array[right] < heap_array[min_index]){
                min_index = right;
            }

            if (min_index != current_index) {
                std::swap(heap_array[current_index], heap_array[min_index]);
                current_index = min_index;
            }
            else {
                break;
            }
        }
        return tmp;
    }
    void display() {
        display_array();
    }
};

void heap_sort(std::vector<int>& array) {
    heap h;
    for (auto& item : array) {
        h.insert(item);
    }
    int i = 0;
    for (auto& item : array) {
        array[i++] = h.delete_element();
    }
}

int main() {
    std::vector<int> arr = {1, 4, 2, 3, 10, 8};
    heap h;
    h.insert(1);
    h.insert(4);
    h.insert(2);
    h.insert(3);
    h.insert(10);
    h.insert(8);
    std::cout << h.delete_element() << std::endl;
    std::cout << h.delete_element() << std::endl;
    std::cout << h.delete_element() << std::endl;
    std::cout << h.delete_element() << std::endl;
    std::cout << h.delete_element() << std::endl;
    std::cout << h.delete_element() << std::endl;
    return 0;
}