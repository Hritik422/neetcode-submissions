class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* tree(int inx, vector<int>& pre, vector<int> valid) {
        if (inx >= pre.size() || mp[pre[inx]] < valid[0] || mp[pre[inx]] > valid[1]) 
            return nullptr;

        TreeNode* cur = new TreeNode(pre[inx]);

        cur->left = tree(inx + 1, pre, {valid[0], mp[pre[inx]] - 1});
        int skip = 0;
        // Count how many nodes go to the left subtree
        for (int i = inx + 1; i < pre.size(); ++i) {
            if (mp[pre[i]] >= valid[0] && mp[pre[i]] < mp[pre[inx]]) {
                ++skip;
            }
        }
        cur->right = tree(inx + 1 + skip, pre, {mp[pre[inx]] + 1, valid[1]});
        
        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
                                                            mp[inorder[i]] = i;
        }

        return tree(0, preorder, {0, int(preorder.size() - 1)});
    }
};
