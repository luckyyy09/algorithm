#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left <= right) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
                mid = (left + right) / 2;
            } else if (nums[mid] > target) {
                right = mid - 1;
                mid = (left + right) / 2;
            }
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;

        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        int index = -1;
        if (nums[left] > nums[right]) {
            if (target < nums[left] && target > nums[right]) {
                return index;
            } else if (target <= nums[left] && target <= nums[right]) {
                // Todo: target in right part
                if (nums[mid] == target) return mid;
                while (left <= right) {
                    if (nums[mid] < target) {
                        left = mid + 1;
                        mid = (left + right) / 2;
                    } else if (nums[mid] > target && nums[mid] < nums[right]) {
                        right = mid - 1;
                        mid = (left + right) / 2;
                    } else if (nums[mid] > target && nums[mid] > nums[right]) {
                        left = mid + 1;
                        mid = (left + right) / 2;
                    } else if (nums[mid] == target) {
                        return mid;
                    } else {
                        return -1;
                    }
                }
            } else if (target >= nums[left]) {
                // Todo: target in left part
                while (left <= right) {
                    if (nums[mid] == target) {
                        return mid;
                    } else if (nums[mid] < target && nums[mid] < nums[right]) {
                        right = mid - 1;
                        mid = (left + mid) / 2;
                    } else if (nums[mid] < target && nums[mid] > nums[right]) {
                        left = mid + 1;
                        mid = (left + right) / 2;
                    } else if (nums[mid] > target) {
                        right = mid - 1;
                        mid = (left + right) / 2;
                    } else {
                        return -1;
                    }
                }
            }
        } else {
            // Todo: binarySearch
            index = binarySearch(nums, target);
        }
        return index;
    }
};

int main() {
    Solution a;
    vector<int> nums = {4,5,6,7,0,1,2};
    int tmp = a.search(nums, 6);
    cout << tmp << endl;
    return 0;
}