class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 0;
        
        sort(intervals.begin(), intervals.end());
        
        int count = 0;
        int prev_End = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(prev_End <= intervals[i][0]){
                prev_End = intervals[i][1];
            }
            else{
                prev_End = min(prev_End, intervals[i][1]);
                count++;
            }
        }
        return count;
    }
};