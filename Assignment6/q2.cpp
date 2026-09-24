#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class PostfixEvaluator{
public:
    int evalRPN(vector<string>& tokens){
        stack<int> s;
        for(string token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if(token == "+") s.push(a+b);
                else if(token == "-") s.push(a-b);
                else if(token == "*") s.push(a*b);
                else if(token == "/") s.push(a/b);

            } else{
                s.push(stoi(token)); // to convert number into integer 
            }
        }
        return s.top();
    }
};

int main(){
    PostfixEvaluator evaluator;

    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};;

    cout << "Input: tokens1.." << endl;
    cout << "Output: Result: " << evaluator.evalRPN(tokens1) << endl;

    cout << "Input: tokens2.." << endl;
    cout << "Output: Result: " << evaluator.evalRPN(tokens2) << endl;

    return 0;
}