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
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);

        return root;
    }
private:
    void dfs(TreeNode* node){
        if(node==nullptr)
            return;
        
        invert_node(node);
        dfs(node->left);
        dfs(node->right);
    }
    void invert_node(TreeNode* node){
        TreeNode* temp;
        temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
};