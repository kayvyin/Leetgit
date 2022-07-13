class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = {p1, p2, p3, p4};
        
        unordered_set<int> lengths;
        
        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                int x_dist = abs(p[i][0] - p[j][0]);
                int y_dist = abs(p[i][1] - p[j][1]);
                
                int dist = x_dist *  x_dist + y_dist * y_dist;
                
                if(dist > 0){
                    lengths.insert(dist);
                }
                else{
                    return false;
                }
            }
        }
        return lengths.size() == 2;
        
        
    }
};