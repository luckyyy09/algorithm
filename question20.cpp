#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (char_stack.empty()) return false;
                if (char_stack.top() == '(') {
                    char_stack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (char_stack.top() == '[') {
                    if (char_stack.empty()) return false;
                    char_stack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (char_stack.empty()) return false;
                if (char_stack.top() == '{') {
                    char_stack.pop();
                } else {
                    return false;
                }
            } else if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                char_stack.push(s[i]);
            }
        }
        if (char_stack.empty()) {
            return true;
        } else {
            return false;
        }

    }
};

int main() {
    Solution a;
    string s = "[]";
    bool ret = a.isValid(s);
    cout << ret << endl;
    return 0;
}