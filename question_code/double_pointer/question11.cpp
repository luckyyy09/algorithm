#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int min(int num1, int num2) {
        return num1 < num2 ? num1 : num2;
    }
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max = (right - left) * min(height[left], height[right]);
        while (left < right)
        {
            int tmp = (right - left) * min(height[left], height[right]);
            if (tmp > max) {
                max = tmp;
            }
            if (min(height[left + 1], height[right]) > min(height[left], height[right - 1])) {
                left++;
            } else if (min(height[left + 1], height[right]) < min(height[left], height[right - 1])) {
                right--;
            } else {
                if (height[left + 1] > height[right - 1]) {
                    left++;
                } else {
                    right--;
                }
            }
            
            // if (height[left + 1] - height[left] > height[right - 1] - height[right]) {
            //     left++;
            // } else if (height[left + 1] - height[left] < height[right - 1] - height[right]) {
            //     right--;
            // } else if (height[left + 1] - height[left] > 0) {
            //     if (height[left] < height[right]) {
            //         left++;
            //     } else {
            //         right--;
            //     }
            // } else {
            //     if (height[left] < height[right]) {
            //         right--;
            //     } else {
            //         left++;
            //     }
            // }
        }
        return max;

    }
};

int main() {
    Solution a;
    vector<int> height = {1,3,2,5,25,24,5};
    int max = a.maxArea(height);
    cout << max << endl;
    return 0;
}