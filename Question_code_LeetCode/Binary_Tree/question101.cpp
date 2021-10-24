/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* root, vector<int>& inOrder) {
        if (root == nullptr) {
            return;
        } else {
            dfs(root->left, inOrder);
            inOrder.push_back(root->val);
            dfs(root->right, inOrder);
        }
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        dfs(root, inOrder);
        for (int i = 0; i < inOrder.size() - 1; i++) {
            if(inOrder[i + 1] <= inOrder[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
