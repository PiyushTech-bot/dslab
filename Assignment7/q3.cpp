#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class HistogramOptimizer {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // Sentinel height of 0 forces clearing the stack at the end
            int current_height = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && current_height < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : (i - st.top() - 1);
                max_area = max(max_area, h * w);
            }
            st.push(i);
        }
        return max_area;
    }
};

int main() {
    HistogramOptimizer optimizer;
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    vector<int> heights2 = {2, 4};

    cout << "Input heights: [2, 1, 5, 6, 2, 3]" << endl;
    cout << "Max Rectangular Area: " << optimizer.largestRectangleArea(heights1) << endl;

    cout << "\nInput heights: [2, 4]" << endl;
    cout << "Max Rectangular Area: " << optimizer.largestRectangleArea(heights2) << endl;

    return 0;
}