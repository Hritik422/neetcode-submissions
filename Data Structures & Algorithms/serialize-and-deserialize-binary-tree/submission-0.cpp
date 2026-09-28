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

class Codec {
private:
    void serilalizeTree(TreeNode* node, vector<string>& res){
        if (!node) {
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        serilalizeTree(node->left, res);
        serilalizeTree(node->right, res);
    }
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    TreeNode* deserializeTree(vector<string>& data, int& i){
         if(data[i]=="N"){
            i++;
            return NULL;
         }
         TreeNode* myTree = new TreeNode(stoi(data[i]));
         i++;
         myTree -> left = deserializeTree(data, i);
         myTree -> right = deserializeTree(data, i);

         return myTree;
    }
public:
    string serialized;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        serilalizeTree(root, res);
        string ser;
        for(auto it:res){
            ser+= it+",";
        }
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
       int i=0;
        return deserializeTree(vals, i);
    }
};
