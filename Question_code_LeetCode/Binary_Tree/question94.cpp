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
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};

        vector<int> inOrderVector;
        dfs(root, inOrderVector);
        return inOrderVector;
    }
};