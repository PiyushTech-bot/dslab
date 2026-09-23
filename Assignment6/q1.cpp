#include <iostream>
#include <stack>
#include <string>

using namespace std;

class ParenthesesChecker {
public:
    bool isValid(string expr) {
        stack<char> s;
        for (char c : expr) {
            // Push open brackets onto stack
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } 
            // Handle closing brackets
            else if (c == ')' || c == '}' || c == ']') {
                if (s.empty()) return false;
                char top = s.top();
                s.pop();
                // Check for matching pairs using single quotes for character literals
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        // Valid iff stack is empty at the end
        return s.empty();
    }
};

int main() {
    ParenthesesChecker checker;
    string expr1 = "{[()]}";
    string expr2 = "{[(])}";

    cout << "Input: expression = \"" << expr1 << "\"" << endl;
    cout << "Output: Valid Syntax: " << (checker.isValid(expr1) ? "True" : "False") << endl;

    cout << "\nInput: expression = \"" << expr2 << "\"" << endl;
    cout << "Output: Valid Syntax: " << (checker.isValid(expr2) ? "True" : "False") << " (Mismatch at ']')" << endl;

    return 0;
}