#include <iostream>
#include <string>
#include <stack>

std::string decimalToBaseP(int decimal, int p) {
    std::stack<int> p_s;
    while (decimal > 0) {
        p_s.push(decimal % p);
        decimal /= p;
    }
    std::string result = "";
    while (!p_s.empty()) {
        result += char(p_s.top() + (int)'0');
        p_s.pop();
    }
    return result;
}

int main() {
    std::cout << decimalToBaseP(16, 2) << std::endl;
    return 0; 
}