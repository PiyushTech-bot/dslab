#include <iostream>
#include <string>
#include <stack>

using namespace std;

class BrowserHistory {
private:
    stack<string> back_stack;
    stack<string> forward_stack;
    string current_url;

public:
    BrowserHistory(string homepage) {
        current_url = homepage;
    }

    // Visits a new URL, pushes current URL to back_stack, and clears forward_stack
    void visit(string url) {
        back_stack.push(current_url);
        current_url = url;
        while (!forward_stack.empty()) {
            forward_stack.pop();
        }
    }

    // Moves back up to 'steps' using back_stack
    string back(int steps) {
        while (steps > 0 && !back_stack.empty()) {
            forward_stack.push(current_url);
            current_url = back_stack.top();
            back_stack.pop();
            steps--;
        }
        return current_url;
    }

    // Moves forward up to 'steps' using forward_stack
    string forward(int steps) {
        while (steps > 0 && !forward_stack.empty()) {
            back_stack.push(current_url);
            current_url = forward_stack.top();
            forward_stack.pop();
            steps--;
        }
        return current_url;
    }
};

int main() {
    BrowserHistory browser("homepage.com");

    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    cout << "back(1) -> " << browser.back(1) << endl;
    cout << "forward(1) -> " << browser.forward(1) << endl;

    browser.visit("linkedin.com");
    cout << "visit(\"linkedin.com\") clears forward history" << endl;
    cout << "forward(2) -> " << browser.forward(2) << endl;

    return 0;
}