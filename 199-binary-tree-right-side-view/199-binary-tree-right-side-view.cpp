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
        if(!root) return {};
        
        queue<TreeNode*> queue;
        
        vector<int> ans;
        
        queue.push(root);
        
        while(!queue.empty()){
            int level_size = queue.size();
            for(int i = 0; i < level_size; i++){
                TreeNode *curr = queue.front();
                queue.pop();
                if(i == level_size - 1){
                    ans.push_back(curr->val);
                }
                if(curr->left){
                    queue.push(curr->left);
                }
                if(curr->right){
                    queue.push(curr->right);
                }
            }
        }
        return ans;
    }
};