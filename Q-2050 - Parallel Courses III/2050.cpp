class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>> graph(n + 1);
        for(auto i : relations)
            graph[i[1]].push_back(i[0]);

        vector<bool> done(n + 1, false);
        int answer = 0;
        for(int i = 1; i <= n; i++)
            if(!done[i])
                search(i, graph, time, done, answer);

        return answer;
    }

    int search(int i, vector<vector<int>> &graph, vector<int> &time, vector<bool> &done, int &answer)
    {
        if(done[i])
            return time[i - 1];

        done[i] = true;
        int temp = 0;
        for(auto j : graph[i])
            temp = max(temp, search(j, graph, time, done, answer));

        time[i - 1] += temp;
        answer = max(answer, time[i - 1]);
        return time[i - 1];
    }
};