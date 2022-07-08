class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1;
        int suffix = 1;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            prefix *= nums[i];
            suffix *= nums[nums.size() - 1 - i];
            ans = max(ans, max(prefix, suffix));
            prefix = prefix == 0 ? 1: prefix;
            suffix = suffix == 0 ? 1: suffix;
        }
        return ans; 
    }
};

/*
-2, 0, -1
-3,-2
-2,-6
-3,-2,-4, 0,-3, 0, 2, -1, -1


curr_prod
6
sol
6
*/