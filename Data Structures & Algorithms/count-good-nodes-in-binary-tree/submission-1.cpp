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
    void countNodes(TreeNode* root, int maxi, int& count){
        if(!root)return;
        if(root->val>=maxi)count++;
        maxi = max(maxi, root->val);
        countNodes(root->left, maxi, count);
        countNodes(root->right, maxi, count);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxi = -100, count = 0;
        countNodes(root, maxi, count);
        return count;
    }
};
