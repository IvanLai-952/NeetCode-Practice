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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // the value of lowest ancestor would be between in q and q

        if(root==nullptr)
            return root;

        // lowest common ancestor would in the right subtree
        if(root->val<p->val && root->val<q->val)
            return lowestCommonAncestor(root->right, p, q);

        // lowest common ancestor would in the left subtree
        if(root->val>p->val && root->val>q->val)
            return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};