#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int tmp = -1;
        for (int i = 0; i < nums.size();) {
            tmp = i;
            for (int index = i + 1; index < nums.size(); index++) {
                if (nums[index] == -(nums[i] + nums[i + 1])) {
                    ret.push_back({nums[i], nums[i + 1], nums[index]});
                    break;
                }
            }

            for (int j = i; j < nums.size() - 1;) {
                if (nums[j] == nums[i]) {
                    if (nums[j + 1] != nums[i]) {
                        if (j == i) {
                            i++;
                            break;
                        } else {
                            j++;
                        }
                    } else {
                        j++;
                    }
                } else {
                    i = j - 1;
                    break;
                }
            }
            if (tmp == i) {
              i++;
            }
        }
        return ret;

    }
};

int main() {
    Solution a;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ret;
    ret = a.threeSum(nums);
    return 0;
}