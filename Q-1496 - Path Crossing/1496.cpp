class Solution {
public:
    bool isPathCrossing(string path) {

        int x = 0, y = 0;
        set<pair<int, int>> points;
        points.insert({ x,y });

        for (int i = 0; i < path.length(); i++) {
            if (path[i] == 'N')
            {
                y++;
            }
            if (path[i] == 'S')
            {
                y--;
            }
            if (path[i] == 'E')
            {
                x++;
            }
            if (path[i] == 'W')
            {
                x--;
            }
            auto temp = points.insert({ x,y });
            if (temp.second == false)
                return true;
        }
        return false;
    }
};