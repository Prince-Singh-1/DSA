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
TreeNode* ans=NULL;
    bool check(TreeNode* root,TreeNode* r){
        if(root==r ) return 1;
        if(root==NULL) return 0;
     bool p=   check(root->left,r);
     bool q=   check(root->right,r);
        return p||q;
    }
   void solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return;
        if(root==p || root==q) {ans=root; return;}
        bool f1= check(root->left,p);
        bool f2= check(root->left,q);
        if( f1 && f2) solve(root->left,p,q);
       else if(!f1 && !f2) solve(root->right,p,q);
      else  if( f1 || f2) ans=root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         solve(root,p,q);
         return ans;
    }
};