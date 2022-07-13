class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points{p1, p2, p3, p4};
        
        unordered_set<int> hash;
        
        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                int x_dist = points[i][0] - points[j][0];
                int y_dist = points[i][1] - points[j][1];
                int squared_dist = x_dist * x_dist + y_dist * y_dist;
                if(squared_dist == 0){
                    return false;
                }
                hash.insert(squared_dist);
                if(hash.size() > 2){
                    return false;
                }
            }
        }
        return hash.size() == 2;
    }
};