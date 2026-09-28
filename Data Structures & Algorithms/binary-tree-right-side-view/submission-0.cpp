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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<pair<TreeNode*, int>>q;
        q.push({root, 1});
        vector<int>ans;
        int cur = 0;
        while(!q.empty()){
            TreeNode* current = q.front().first;
            int level = q.front().second;
            q.pop();
            if(cur!=level){
                ans.push_back(current->val);
                cur++;
            }
            if(current->right)q.push({current->right, level+1});
            if(current->left)q.push({current->left, level+1});
           
        }
        return ans;
    }
};
