class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }
        
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end()){
            wordList.push_back(beginWord);
        }
        unordered_map<string, vector<string>> hash;
        for(int i = 0; i < wordList.size(); i++){
            for(int j = 0; j < wordList[i].length(); j++){
                string word = wordList[i];
                word[j] = '*';
                hash[word].push_back(wordList[i]);
            }
        }
        
        unordered_set<string> visited;
        queue<string> queue;
        
        queue.push(beginWord);
        visited.emplace(beginWord);
        int count = 0;
        while(!queue.empty()){
            int size = queue.size();
            count++;
            for(int i = 0; i < size; i++){
                string popped = queue.front();
                if(popped == endWord){
                    return count;
                }
                queue.pop();
                for(int j = 0; j < popped.length(); j++){
                    string pattern = popped;
                    pattern[j] = '*';
                    
                    for(auto it: hash[pattern]){
                        if(visited.find(it) != visited.end()){
                            continue;
                        }
                        else{
                            visited.emplace(it);
                            queue.push(it);
                        }
                    }
                }
            }
        }
        return 0;
    }
};