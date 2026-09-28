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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int cur = 0;
        vector<int>temp;
        while(!q.empty()){
            TreeNode* current = q.front().first;
            int level = q.front().second;
            q.pop();
            if(cur==level)temp.push_back(current->val);
            else{
                ans.push_back(temp);
                temp.clear();
                cur++;
                temp.push_back(current->val);
            }
            if(current->left)q.push({current->left, level+1});
            if(current->right)q.push({current->right, level+1});
        }
        ans.push_back(temp);
        return ans;
    }
};
