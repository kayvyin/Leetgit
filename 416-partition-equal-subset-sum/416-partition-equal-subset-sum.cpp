class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int target = 0;
        int n = nums.size();
        if(n == 1) return false;
        for(int i = 0; i < n; i++){
            target += nums[i];
        }
        if(target % 2 != 0){
            return false;
        }
        
        target /= 2;
        
        unordered_set<int> dp;
        dp.insert(0);
        for(int i = 0; i < n; i++){
            unordered_set<int> next_state;
            
            for(auto it: dp){
                if(it + nums[i] == target){
                    return true;
                }
                next_state.insert(it + nums[i]);
                next_state.insert(it);
            }
            dp = next_state;
        }
        
        return false;
    }
};