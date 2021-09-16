/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (target > nums[nums.size() - 1] || target < nums[0]) {
            return -1;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left <= right) {
            if (nums[mid] < target) {
                left = mid + 1;
                mid = (left + right) / 2;
            } else if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
                mid = (left + right) / 2;
            }
        }
        return -1;
    }
};
// @lc code=end
