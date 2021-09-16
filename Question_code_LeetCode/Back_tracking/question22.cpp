class Solution {
public:
    void backTrack(int n, vector<string>& parenthese, string& parenthese_pair, int& left, int& right) {
        if (left == n && right == n) {
            parenthese.push_back(parenthese_pair);
        } else {

            if (left < n) {
                parenthese_pair.push_back('(');
                left++;
                backTrack(n, parenthese, parenthese_pair, left, right);
                left--;
                parenthese_pair.pop_back();
            } 
            if (left > right && right < n) {
                parenthese_pair.push_back(')');
                right++;
                backTrack(n, parenthese, parenthese_pair, left, right);
                right--;
                parenthese_pair.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        int left = 0;
        int right = 0;
        string parenthese_pair;
        vector<string> parenthese;
        backTrack(n, parenthese, parenthese_pair, left, right);
        return parenthese;

    }
};