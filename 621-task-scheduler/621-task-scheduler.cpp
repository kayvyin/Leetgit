class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        
        for(auto task : tasks){
            hash[task]++;
        }
        
        priority_queue<int> max_heap;
        
        for(auto it: hash){
            if(it.second > 0){
                max_heap.push(it.second);
            }
        }
        queue<pair<int, int>> queue;
        int curr_time = 0;
        while(!max_heap.empty() || !queue.empty()){
            curr_time++;
            if(!max_heap.empty()){
                int count = max_heap.top() - 1;
                max_heap.pop();
                if(count > 0){
                    queue.push(make_pair(count, curr_time + n));
                    
                }
            }
            if(!queue.empty() && queue.front().second == curr_time){
                max_heap.push(queue.front().first);
                queue.pop();
            }
        }
        return curr_time;
    }
};
/*
3 A's
3 B's

max_heap:


time = 4

queue:
2, 4
*/