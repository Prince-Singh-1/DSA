class Solution {
public:
    vector<TreeNode*> path;

    void findPath(TreeNode* root, TreeNode* x,
                  vector<TreeNode*>& v) {
        if (!root || !path.empty()) return;

        v.push_back(root);

        if (root == x) {
            path = v;
            v.pop_back();
            return;
        }

        findPath(root->left, x, v);
        findPath(root->right, x, v);

        v.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {
        vector<TreeNode*> v;

        findPath(root, p, v);
        vector<TreeNode*> p1 = path;

        path.clear();
        v.clear();

        findPath(root, q, v);
        vector<TreeNode*> p2 = path;

        TreeNode* ans = root;

        for (int i = 0; i < min(p1.size(), p2.size()); i++) {
            if (p1[i] == p2[i])
                ans = p1[i];
            else
                break;
        }

        return ans;
    }
};