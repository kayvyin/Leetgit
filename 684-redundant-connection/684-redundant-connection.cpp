class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        par = vector<int>(edges.size() + 1);
        for(int i = 0; i < par.size(); i++){
            par[i] = i;
        }
        for(auto edge : edges){
            if(find(edge[0]) == find(edge[1])){
                return edge;
            }
            else{
                unien(edge[0], edge[1]);
            }
        }
        return edges[0];
    }
private:
    vector<int> par;
    int find(int x){
        if(x != par[x]) par[x] = find(par[x]);
        
        return par[x];
    }
    
    void unien(int x, int y){
        par[find(y)] = find(x);
    }
};