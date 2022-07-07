class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return 1;
        
        vector<int> start_times;
        vector<int> end_times;
        for(auto interval : intervals){
            start_times.push_back(interval[0]);
            end_times.push_back(interval[1]);
        }
        
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());
        
        int s = 0;
        int e = 0;
        int result = 0;
        int count = 0;
        
        while(s < n){
            if(start_times[s] < end_times[e]){
                count++;
                result = max(result, count);
                s++;
            }
            else{
                count--;
                e++;
            }
        }
        return result;
    }
};