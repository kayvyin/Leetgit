class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int jumps = 0;
        while(r < nums.size() - 1){
            int max_reach = 0;
            for(int i = l; i < r + 1; i++){
                max_reach = max(max_reach, i + nums[i]);
            }
            
            l = r + 1;
            r = max_reach;
            jumps++;
        }
        return jumps;
    }
};