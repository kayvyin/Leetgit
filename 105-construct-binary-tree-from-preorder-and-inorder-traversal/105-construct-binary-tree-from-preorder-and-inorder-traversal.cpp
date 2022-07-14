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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return buildHelper(preorder, inorder, index, 0, inorder.size() - 1);
    }
private:
    unordered_map<int, int> m;
    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int &idx, int i, int j){
        if(i > j){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[idx]);
        int split = m[preorder[idx]];
        idx++;
        root->left = buildHelper(preorder, inorder, idx, i, split - 1);
        root->right = buildHelper(preorder, inorder, idx, split + 1, j);
        
        return root;
    }
};