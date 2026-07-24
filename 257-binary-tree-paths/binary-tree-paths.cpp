class Solution {
public:
    vector<string> ans;

    void helper(TreeNode* root, string s) {
        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(s);
            return;
        }

        if (root->left)
            helper(root->left, s + "->" + to_string(root->left->val));

        if (root->right)
            helper(root->right, s + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return {};

        helper(root, to_string(root->val));
        return ans;
    }
};