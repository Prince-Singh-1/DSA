/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> p1;
    TreeNode* ansp = NULL;

    void prince(TreeNode* root, int x) {
        if (!root || ansp) return;

        if (root->val == x) {
            ansp = root;
            return;
        }

        prince(root->left, x);
        prince(root->right, x);
    }

    void helper(TreeNode* root, TreeNode* p, vector<int>& v) {
        if (!root || !p1.empty()) return;

        v.push_back(root->val);

        if (root == p) {
            p1 = v;
            v.pop_back();
            return;
        }

        helper(root->left, p, v);
        helper(root->right, p, v);

        v.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> v;

        helper(root, p, v);
        vector<int> p2 = p1;

        p1.clear();
        v.clear();

        helper(root, q, v);
        vector<int> q2 = p1;

        int x = root->val;

        for (int i = 0; i < min(p2.size(), q2.size()); i++) {
            if (p2[i] == q2[i])
                x = p2[i];
            else
                break;
        }

        ansp = NULL;
        prince(root, x);

        return ansp;
    }
};