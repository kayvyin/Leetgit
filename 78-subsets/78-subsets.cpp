class Solution {
private:
    void backtrack(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int idx){
        ans.push_back(curr);
        
        for(int i = idx; i < nums.size(); i++){
            curr.push_back(nums[i]);
            backtrack(ans, curr, nums, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(ans, curr, nums, 0);
        return ans;
    }
};