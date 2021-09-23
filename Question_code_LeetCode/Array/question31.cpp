class Solution {
public:
    int index(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                return i - 1;
            }
        }
        return -1;
    }

    int secondNum(vector<int>& nums, int index) {
        for (int i = nums.size() - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                return i;
            }
        }
        return -1;
    }

    void swapNum(vector<int>& nums, int index, int secondNum) {
        int tmp = nums[index];
        nums[index] = nums[secondNum];
        nums[secondNum] = tmp;
        return;
    }

    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        } else if (nums.size() == 2) {
            int tmp = nums[0];
            nums[0] = nums[1];
            nums[1] = tmp;
            return;
        }
        int index1 = index(nums);
        if (index1 == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        int secondNum1 = secondNum(nums, index1);
        swapNum(nums, index1, secondNum1);
        vector<int>::iterator it = nums.begin();
        it += index1 + 1;
        sort(it, nums.end());
        return;

    }
};