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
        
        for(auto it: m){
            int card = it.first;
            while(it.second-- > 0){
                for(int i = 1; i < groupSize; i++){
                    if(m.find(card + i) == m.end() || m[card + i]-- == 0) return false;
                }
            }
        }
        return true;
    }
};