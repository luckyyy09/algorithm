/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int codingNumbers(char a, char b) {
        int left = a - '0';
        int right = b - '0';
        int sum = left * 10 + right;
        if (sum <= 9 && sum >= 1) {
            return 1;
        } else if (sum == 10 || sum == 20) {
            return 2;
        } else if (sum >= 11 && sum <= 26) {
            return 3;
        } else if (sum == 0 || (left > 2 && right == 0)) {
            return 0;
        } else if (sum > 26) {
            return 1;
        }
        return -1;

    }
    int numDecodings(string s) {
        if (s[0] == '0') 
            return 0;
        if (s.size() == 1)
            return 1;
        vector<int> dp(s.size());
        dp[0] = 1;
        int tmp = codingNumbers(s[0], s[1]);
        if (tmp == 1) {
            dp[1] = dp[0];
        } else if (tmp == 2) {
            dp[1] = 1;
        } else if (tmp == 3) {
            dp[1] = 2;
        } else {
          return 0;
        }
        if (s.size() == 2) {
            return dp[1];
        }

        for (int i = 2; i < s.size(); i++) {
            if (codingNumbers(s[i - 1], s[i]) <= 0 ) {
                return 0;
            } else if (codingNumbers(s[i - 1], s[i]) == 1) {
                dp[i] = dp[i - 1];
            } else if (codingNumbers(s[i - 1], s[i]) == 2) {
                dp[i] = dp[i -2];
            } else if (codingNumbers(s[i - 1], s[i]) == 3) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        return dp[s.size() - 1];

    }
};
// @lc code=end
