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
    bool ans=false;
    bool isSame(TreeNode* p, TreeNode* q){
        if (!p && !q) return true;           
        if (!p || !q) return false;          
        if (p->val != q->val) return false;  
        return isSame(p->left, q->left) && isSame(p->right, q->right);
    }
    void check(TreeNode* root ,TreeNode* subRoot){
        if(!root)return;

        if(!ans && root->val == subRoot->val){
           ans=isSame(root, subRoot);
        }else if(ans)return;
        if(root->left)check(root->left, subRoot);
        if(root->right)check(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        check(root, subRoot);
        return ans;
    }
};
