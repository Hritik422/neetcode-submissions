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
    int find(TreeNode* root){
        if(!root)return 0;
        int l = 1 + find(root->left);
        int r = 1 + find(root->right);
        return max(l, r);
    }
    int maxDepth(TreeNode* root) {
        return find(root);
    }
};
