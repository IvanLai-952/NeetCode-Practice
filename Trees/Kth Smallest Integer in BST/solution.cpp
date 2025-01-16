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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count=k;
        DFS(root, ans, count);

        return ans;
    }
private:
    void DFS(TreeNode* node, int& val, int &count){
        if(node==nullptr)   return;

        DFS(node->left, val, count);
        if(--count==0){
            val=node->val;
            return;
        }
        DFS(node->right, val, count);
    }
};