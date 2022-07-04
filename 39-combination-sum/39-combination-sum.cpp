class Solution {
private:
    void backtracking(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &curr, int curr_sum, int target, int idx){
        if(curr_sum > target){
            return;
        }
        if(curr_sum == target){
            ans.push_back(curr);
        }
        for(int i = idx; i < candidates.size(); i++){
            curr.push_back(candidates[i]);
            backtracking(ans, candidates, curr, curr_sum + candidates[i], target, i);
            curr.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        
        backtracking(ans, candidates, curr, 0, target, 0);
        return ans;
    }
};