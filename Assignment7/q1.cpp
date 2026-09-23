#include <iostream>
#include <string>
#include <stack>

using namespace std;

class InfixToPostfix {
private:
    // Helper function to return operator precedence
    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

public:
    string convert(string s) {
        stack<char> st;
        string result = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // If the character is an operand, add it to the output string
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                result += c;
            }
            // If the character is '(', push it to the stack
            else if (c == '(') {
                st.push('(');
            }
            // If the character is ')', pop and output from the stack until '(' is encountered
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop(); // Pop the '('
                }
            }
            // If an operator is encountered
            else {
                while (!st.empty() && precedence(c) <= precedence(st.top())) {
                    if (c == '^' && st.top() == '^') break;
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop all remaining operators from the stack
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    InfixToPostfix translator;
    string expression = "a+b*(c^d-e)/(f+g*h)-i";

    cout << "Input Expression: " << expression << endl;
    cout << "Postfix Expression: " << translator.convert(expression) << endl;

    return 0;
}
