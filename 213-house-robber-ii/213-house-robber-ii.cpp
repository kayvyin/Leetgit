class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() - 1));
    }
private:
    int helper(vector<int>& nums, int idx, int end){
        int rob1 = 0, rob2 = 0;
        
        for(int i = idx; i <= end; i++){
            int newRob = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        
        return rob2;
    }
};