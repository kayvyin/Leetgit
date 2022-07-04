class Solution {
private:
    void backtracking(vector<vector<int>>& ans, vector<int>& curr, vector<int>& candidates, int remain, int idx){
        if(remain < 0){
            return;
        }
        if(remain == 0){
            ans.push_back(curr);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i - 1]){
                continue;
            }
            if(remain - candidates[i] < 0){
                break;
            }
            curr.push_back(candidates[i]);
            backtracking(ans, curr, candidates, remain - candidates[i], i + 1);
            curr.pop_back();
        }
        
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtracking(ans, curr, candidates, target, 0);
        
        return ans;
    }
};