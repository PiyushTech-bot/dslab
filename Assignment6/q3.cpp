#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpanner{
private:
    stack<pair<int, int>> st; //declares a stack named st that stores elements as pairs: {price, span}

public:
    int next(int price){ // a member function that takes today's stock price as input and returns its calculated span value
        int span = 1; // initializes the span of the current day to 1

        while(!st.empty() && st.top().first <= price){
            span += st.top().second; // adds the span of the smaller/equal price
            st.pop(); // removes the smaller/equal values from the stack
        }
        st.push({price, span});
        return span;
    }
};

int main(){
    StockSpanner spanner;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    cout << "Input Calls: next(100), next(80), next(60), next(70), next(60), next(75), next(85)" << endl;
    cout << "Output Spans: [";
    for(size_t i = 0; i < prices.size(); ++i){
        cout << spanner.next(prices[i]); //calls the next() method for the current price and immediately prints the returned span value
        if(i + 1 < prices.size()) cout << ", "; //checks if the current element is not the last one; if true, prints a comma 
    }
    cout << "]" << endl;
    return 0;
}