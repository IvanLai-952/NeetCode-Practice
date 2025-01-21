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
    int maxDepth(TreeNode* root) {
        return DFS(root, 0);
    }
private:
    int DFS(TreeNode* node, int deep){

        if(node==nullptr){
            return deep;
        }

        return max(DFS(node->left, deep+1), DFS(node->right, deep+1));
    }
};