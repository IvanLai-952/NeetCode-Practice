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
    bool isValidBST(TreeNode* root) {
        
        return DFS(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool DFS(TreeNode* node, long long min_val, long long max_val){
        if(node==nullptr)
            return true;

        // compare boundary value
        if(node->val<=min_val || node->val>=max_val)
            return false;

        // node_val is the max value of left subtree
        // node_val is the min value of right subtree
        return DFS(node->left, min_val, node->val)&&DFS(node->right, node->val, max_val);
    }
};