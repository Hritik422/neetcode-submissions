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
    bool ans=true;
    int check(TreeNode* root){
        if(!root)return 0;
        int l = 1 + check(root->left);
        int h = 1 + check(root->right);
        if(abs(l-h)>1)ans=false;
        return max(l,h);
    }
    bool isBalanced(TreeNode* root) {
         check(root);
         return ans;
    }
};
