class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* cur = root;
        TreeNode* last = nullptr;

        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* node = st.top();

                if (node->right && node->right != last)
                    cur = node->right;
                else {
                    ans.push_back(node->val);
                    last = node;
                    st.pop();
                }
            }
        }

        return ans;
    }
};