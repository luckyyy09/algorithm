class Solution {
public:
    void backTrack(vector<vector<int>>& permutation, vector<int>& nums, vector<int>& tmp_array) {
        if (tmp_array.size() == nums.size()) {
            permutation.push_back(tmp_array);
        } else {
            for (int i = tmp_array.size(); i < nums.size(); i++) {
                tmp_array.push_back(nums[i]);
                int tmp = nums[i];
                nums[i] = nums[tmp_array.size() - 1];
                nums[tmp_array.size() - 1] = tmp;
                backTrack(permutation, nums, tmp_array);
                tmp = nums[tmp_array.size() - 1];
                nums[tmp_array.size() - 1] = nums[i];
                nums[i] = tmp;
                tmp_array.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> tmp_array;
        backTrack(ret, nums, tmp_array);
        return ret;
    }
};