class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }
        
        map<int, int> m;
        
        for(auto card: hand){
            m[card]++;
        }
        
        while(!m.empty()){
            int curr  = m.begin()->first;
            for(int i = 0; i < groupSize; i++){
                if(m.find(curr + i) == m.end()){
                    return false;
                }
                if(--m[curr + i] < 1){
                    m.erase(curr + i);
                }
                
            }
        }
        return true;
    }
};