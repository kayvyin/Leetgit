class Solution {
public:
    struct Compare{
        bool operator()(pair<int, int> x, pair<int, int> y){
            int dist1 = abs(x.first) * abs(x.first) + abs(x.second) * abs(x.second);
            int dist2 = abs(y.first) * abs(y.first) + abs(y.second) * abs(y.second);
            return dist1 < dist2;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> max_heap;
        
        for(auto point : points){
            max_heap.push(make_pair(point[0], point[1]));
            if(max_heap.size() > k){
                max_heap.pop();
            }
        }
        vector<vector<int>> ans;
        while(!max_heap.empty()){
            auto point = max_heap.top();
            max_heap.pop();
            ans.push_back({point.first, point.second});
        }
        return ans;
    }
};