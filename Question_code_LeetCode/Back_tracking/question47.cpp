class Solution {
public:
    void backTrack(set<vector<int>>& permutation, vector<int>& nums, vector<int>& num_array) {
        if (num_array.size() == nums.size()) {
            permutation.insert(num_array);
        } else {
            for (int i = num_array.size(); i < nums.size(); i++) {
                num_array.push_back(nums[i]);
                int tmp = nums[i];
                nums[i] = nums[num_array.size() - 1];
                nums[num_array.size() - 1] = tmp;
                backTrack(permutation, nums, num_array);
                tmp = nums[i];
                nums[i] = nums[num_array.size() - 1];
                nums[num_array.size() - 1] = tmp;
                num_array.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        set<vector<int>> tmp;
        vector<int> array;
        backTrack(tmp, nums, array);
        for (set<vector<int>>::iterator it = tmp.begin(); it != tmp.end(); it++) {
            ret.push_back(*it);
        }
        return ret;

    }
};