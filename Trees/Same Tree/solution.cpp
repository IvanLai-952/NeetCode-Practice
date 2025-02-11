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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
private:
    bool dfs(TreeNode* p, TreeNode* q){

        if(p==nullptr && q==nullptr)
            return true;
        
        if(p==nullptr || q==nullptr)
            return false;
        
        return (p->val==q->val)&&dfs(p->left, q->left)&&dfs(p->right, q->right);
    }
};