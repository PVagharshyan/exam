#include <iostream>
#include <stack>
#include <map>

const int count_sims = 6;
char arr_sims[count_sims] = {'(', ')', '+', '-', '*', '/'};

int priority(char c) {
    std::map<char, int> m;
    for (int i {}; i < count_sims; ++i) {
        m[arr_sims[i]] = i;
    }
    return m[c];
}

bool is_operant(char c) {
    std::cout << c << std::endl;
    for (int i {}; i < count_sims; ++i) {
        if (c == arr_sims[i]) return true;
    }
    return false;
}

int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }
int Div(int a, int b) { 
    if (!b) return 0;
    return a / b;
}
int Mul(int a, int b) { return a*b; }

std::string in_post(const std::string& str) {
    std::stack<char> s;
    std::string result = "";
    for (int i {}; i < str.size(); ++i) {
        if ('0' <= str[i] && str[i] <= '9') {
            result += str[i];
        }
        else if (is_operant(str[i])) {
            if (s.empty() || str[i] == '(') {
                s.push(str[i]);
            }
            else if (str[i] == ')') {
                char current_sim = s.top();
                while (current_sim != '(') {
                    result += current_sim;
                    s.pop();
                    current_sim = s.top();
                }
                s.pop();
            }
            else {
                while (priority(s.top()) >= priority(str[i])) {
                    result += s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
        else {
            throw std::runtime_error("Error...");
        }
    }
    return result;
}

int result_exp(const std::string& str) {
    std::map<char, int(*)(int, int)> op;
    op['+'] = Add;
    op['-'] = Sub;
    op['*'] = Mul;
    op['/'] = Div;
    std::stack<int> s;
    for (int i {}; i < str.size(); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            s.push(str[i] - (int)'0');
        }
        else {
            int operant_1 = s.top();
            s.pop();
            int operant_2 = s.top();
            s.pop();
            s.push(op[str[i]](operant_2, operant_1));
        }
    }
    return s.top();
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

std::string postfixToPrefix(const std::string& postfix) {
    std::stack<std::string> stack;
    
    for (char c : postfix) {
        if (!is_operator(c)) {
            stack.push(std::string(1, c));
        } else {
            std::string operand2 = stack.top();
            stack.pop();
            std::string operand1 = stack.top();
            stack.pop();

            std::string result = c + operand1 + operand2;
            stack.push(result);
        }
    }

    return stack.top();
}

int main() {
    std::string postfixExpression = "73-26*-";
    std::string prefixExpression = postfixToPrefix(postfixExpression);

    std::cout << "Postfix: " << postfixExpression << std::endl;
    std::cout << "Prefix: " << prefixExpression << std::endl;

    return 0;
}


// int main() {
//     std::string input = "((7-3)/(2*(7-6)))";
//     std::string output = in_post(input);
//     std::cout << output << std::endl; 
//     std::cout << result_exp(output) << std::endl;
//     return 0;
// }