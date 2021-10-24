#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left,right(heights.size());
        stack<int> int_stack;
        for (int i = 0; i < heights.size(); i++) {
            if (i == 0) {
                int_stack.push(i);
                left.push_back(-1);
                continue;
            }
            if (heights[i] > heights[int_stack.top()]) {
                left.push_back(int_stack.top());
                int_stack.push(i);
            } else {
                while (!int_stack.empty() && heights[i] <= heights[int_stack.top()]) {
                    int_stack.pop();
                }
                if (int_stack.empty()) {
                    left.push_back(-1);
                    int_stack.push(i);
                } else if (heights[i] > heights[int_stack.top()]) {
                    left.push_back(int_stack.top());
                    int_stack.push(i);
                }
            }
        }

        stack<int> int_stack1;
        int size = heights.size() - 1;
        for (int i = size; i >= 0; i--) {
            if (i == size) {
                int_stack1.push(i);
                right.push_back(size + 1);
                continue;
            }

            if (heights[i] > heights[int_stack1.top()]) {
                right.push_back(int_stack1.top());
                int_stack1.push(i);
            } else {
                while (!int_stack1.empty() && heights[i] <= heights[int_stack1.top()]) {
                    int_stack1.pop();
                }
                if (int_stack1.empty()) {
                    right.push_back(size + 1);
                    int_stack1.push(i);
                } else if (heights[i] > heights[int_stack1.top()]) {
                    right.push_back(int_stack1.top());
                    int_stack1.push(i);
                }
            }
        }
        vector<int> right1;
        for (int i = 0; i < right.size(); i++) {
            right1.push_back(right[right.size() - 1 - i]);
        }
        int max = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (max < (right1[i] - left[i] - 1) * heights[i]) {
                max = (right1[i] - left[i] - 1) * heights[i];
            }
        }
        return max;
    }
};

int main() {
    Solution a;
    vector<int> height = {2,1,5,6,2,3};
    int max = a.largestRectangleArea(height);
    cout << max << endl;
    return 0;
}