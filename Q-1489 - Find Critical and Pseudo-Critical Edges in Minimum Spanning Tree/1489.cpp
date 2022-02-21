class Solution {
public:
    static bool compare(vector<int>&v1, vector<int>&v2){
        return v1[2] < v2[2];
    }
    vector<int> vec;
    int find(int x){
        if(vec[x] == -1){
            return x;
        }
        return find(vec[x]);
    }
	

    int tree(vector<vector<int>> &edges,vector<int> &in,vector<int> &ex){     
        int x = 0;
        if(in.size()){
            vec[in[0]] = in[1];
            x += in[2];
        }
        for(auto i:edges){
            if(i == ex){
                continue;
            }
            int item1 = find(i[0]);
            int item2 = find(i[1]);
            if(item1 != item2){
                vec[item1] = item2;
                x += i[2];
            }
        }
        
        int no_of_vec = 0;       
        for(auto i:vec){
            if(i == -1){
                no_of_vec++;
            }
        }
        if(no_of_vec>1)
        {
            return INT_MAX;
        }
        return x;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) {
            vec.push_back(-1);   
        }
        for(auto i = 0; i < edges.size(); i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), compare);
        vector<int> temp;
        vector<vector<int>> answer(2);
        int min = tree(edges,temp,temp);

        for(auto i:edges) {                            
            for(int j = 0;j < n; j++) {
                vec[j] = -1;
            }
            int ec = tree(edges,temp,i);
            if(ec > min) {
                answer[0].push_back(i[3]);
            }
            else {
                for(int j=0;j<n;j++) {
                    vec[j]=-1;
                }
                int ic=tree(edges,i,temp);
                if(ic==min)
                {
                    answer[1].push_back(i[3]);
                }
            }
        }
        return answer;
    }
};