#include <iostream>
#include <stack>
#include <vector>
#include <utitlity>
using namespace std;

class StockSpanner{
private:
    stack<pair<int, int>> st;

public:
    int next(int price){
        int span = 1;

        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
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
        cout << spanner.next(prices[i]);
        if(i + 1 < prices.size()) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}