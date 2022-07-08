class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return n == 1 ? nums[0] : max(nums[0], nums[1]);
        }
        int rob1 = 0, rob2 = 0;
        
        for(auto num : nums){
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};