/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:

    void backTrack(vector<string>& combinations, vector<string>& phone_number, string digits, int index, string& combination) {
        if (index == digits.size()) {
            combinations.push_back(combination);
        } else {
            string letters = phone_number[digits[index] - '0'];
            for (int i = 0; i < letters.size(); i++) {
                combination.push_back(letters[i]);
                backTrack(combinations, phone_number, digits, index + 1, combination);
                combination.pop_back();
            }

        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        int len = digits.size();

        string char_2 = "abc";
        string char_3 = "def";
        string char_4 = "ghi";
        string char_5 = "jkl";
        string char_6 = "mno";
        string char_7 = "pqrs";
        string char_8 = "tuv";
        string char_9 = "wxyz";

        vector<string> phone_number = {"", "", char_2, char_3, char_4,
        char_5, char_6, char_7, char_8, char_9};
        vector<string> ret;
        string letter = "";

        backTrack(ret, phone_number, digits, 0, letter);
        return ret;
    }
};
// @lc code=end
