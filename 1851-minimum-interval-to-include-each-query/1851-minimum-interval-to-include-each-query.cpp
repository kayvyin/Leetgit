class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;
        vector<int> sorted_queries = queries;
        
        sort(intervals.begin(), intervals.end());
        sort(sorted_queries.begin(), sorted_queries.end());
        
        unordered_map<int,int> m;
        
        vector<int> ans;
        int i = 0;
        for(int q  = 0; q < queries.size(); q++){
            int query = sorted_queries[q];
            while(i < intervals.size() && intervals[i][0] <= query){
                int size = intervals[i][1] - intervals[i][0] + 1;
                min_heap.push(make_pair(size, intervals[i][1]));
                i++;
            }
            while(!min_heap.empty() && min_heap.top().second < query){
                min_heap.pop();
            }
            if(!min_heap.empty()){
                m[query] = min_heap.top().first;
            }
            else{
                m[query] = -1;
            }
        }
        
        for(int k = 0; k < queries.size(); k++){
            ans.push_back(m[queries[k]]);
        }
        return ans;
    }
};