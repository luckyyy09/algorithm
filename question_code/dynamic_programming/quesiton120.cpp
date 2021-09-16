/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = row;
        vector<vector<int>> dp(row, vector<int>(col));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }

        for (int i = 2; i < row; i++) {
            for (int j = 1; j < i; j++) {
                if (dp[i - 1][j - 1] > dp[i -1][j]) {
                    dp[i][j] = dp[i -1][j] + triangle[i][j];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }
            }
        }

        int min = dp[row - 1][0];
        for (int i = 1; i < col; i++) {
            if (dp[row - 1][i] < min) {
                min = dp[row - 1][i];
            }
        }
        return min;
    }
};
// @lc code=end
