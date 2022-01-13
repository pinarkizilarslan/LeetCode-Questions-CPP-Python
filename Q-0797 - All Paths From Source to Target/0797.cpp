class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> multiPath = {};

        vector<int> singlePath;
        recursiveDFS(singlePath, 0, multiPath, graph);
        return multiPath;
    }
    void recursiveDFS(vector<int> &singlePath, int index, vector<vector<int>> &multiPath, vector<vector<int>> &graph)
    {
        singlePath.push_back(index);
        if (index == graph.size() - 1)
        {
            multiPath.push_back(singlePath);
            return;
        }
        for (int i = 0; i < graph[index].size(); i++)
        {
            if (graph[index][i])
            {
                recursiveDFS(singlePath, graph[index][i], multiPath, graph);
                singlePath.pop_back();
            }
        }
    }
};