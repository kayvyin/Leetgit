class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 0;
        
        sort(intervals.begin(), intervals.end());
        
        int count = 0;
        
        int l = 0, r = 1;
        
        while(r < intervals.size()){
            if(intervals[l][1] <= intervals[r][0]){
                l = r;
                r++;
            }
            else if(intervals[l][1] > intervals[r][1]){
                count++;
                l = r;
                r++;
            }
            else{
                count++;
                r++;
            }
        }
        return count;
    }
};