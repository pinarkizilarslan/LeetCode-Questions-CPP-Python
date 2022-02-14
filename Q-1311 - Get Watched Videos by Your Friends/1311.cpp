class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {        
        vector<vector<int>> graph(watchedVideos.size());        
        for(int i = 0;i != friends.size(); i++){
            for(auto &f: friends[i]){
                graph[f].push_back(i);
                graph[i].push_back(f);
            }
        }
        
        int tempLevel = 0;            
        vector<int> isWatched(watchedVideos.size(),0);            
        vector<string> answer;        
        queue<int> queue;            
        queue.push(id);
            
        while(!queue.empty()){
            if(tempLevel++ == level){
                unordered_map<string,int> map;
                while(!queue.empty()){
                    int tempFront = queue.front(); 
                    queue.pop();
                    if(isWatched[tempFront])
                    {
                        continue;
                    }
                    isWatched[tempFront] = 1;
                    for(auto &i: watchedVideos[tempFront]) {                    
                        map[i]++;
                    }
                }
                set<pair<int,string>> pair;  
            
                for(auto &[key, value]: map){
                    pair.insert({value,key});
                }
            
                for(auto &it: pair){
                    answer.push_back(it.second);
                }
            }
                        
            int n = queue.size();
            while(n--){
                int tempFront = queue.front(); 
                queue.pop();
                if(isWatched[tempFront]){
                    continue;
                }
                isWatched[tempFront] = 1;
            
                for(auto &i: graph[tempFront]){
                    if(!isWatched[i]) 
                    {
                        queue.push(i);
                    }
                }
            }
        }
        
        return answer;
    }
};