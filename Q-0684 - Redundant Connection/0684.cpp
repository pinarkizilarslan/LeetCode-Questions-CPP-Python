class Solution {
public:
    int find(int i , int * parent) {        
        if(parent[i] == -1)
            return i;        
        parent[i] = find(parent[i], parent);
        return parent[i];
    }
    
    void set(int i , int j , int* parent, int * level) {        
        if(level[i] < level[j]){
            parent[i] = j;
            level[j] += level[i];
        }
        else {
            parent[j] = i;
            level[i] += level[j];
        }       
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int * parent = new int [edges.size() + 1];
        int * level = new int[edges.size() + 1];
        for(int i = 0 ; i < edges.size () + 1 ; i ++) {
             parent[i] = -1;
             level[i] = 1;
        }        
        vector <int> answer;        
        for(auto edge : edges) {            
            int s1 = find(edge[0], parent);
            int s2 = find(edge[1], parent);            
            if(s1 != s2) {
                set(s1, s2, parent, level);
            }
            else {
                answer.push_back(edge[0]);
                answer.push_back(edge[1]);
                break;
            }
  
        }
        return answer;
    }
};