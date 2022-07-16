
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        map<int, int> freq;
        
        while(lo <= hi){
            int sol = getPow(lo);
            freq[lo] = sol;
            lo++;
        }
        
        vector<pair<int, int> > result;
        map<int, int>::iterator it;
        
        for(auto it : freq){
            result.push_back({it.first, it.second});
        }
        
        sort(result.begin(), result.end(),
            [](const pair<int, int> &a, const pair<int, int> &b){
                if(a.second != b.second) return (a.second < b.second);
                else return a.first < b.first;
        });
        
        return result[k - 1].first;
    }
    
    int getPow(int x){
        int count = 0;
        if(x == 1) return 1;
        while(x != 1){
            if(x % 2 == 0) x = x / 2;
            else x = (3 * x) + 1;
            count++;
        }
        
        return count;
    }
};