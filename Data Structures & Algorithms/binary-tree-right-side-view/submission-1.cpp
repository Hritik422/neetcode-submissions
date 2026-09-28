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
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        vector<int>temp;
        q.push({root, 0});
        while(!q.empty()){
            int lvl = q.front().second;
            TreeNode* curNode = q.front().first;
            if(ans.size()>lvl)ans[lvl] = curNode->val;
            else ans.push_back(curNode->val);
            q.pop();
            if(curNode->left)q.push({curNode->left, lvl+1});
            if(curNode->right)q.push({curNode->right, lvl+1});
        }
        return ans;       
    }
};
