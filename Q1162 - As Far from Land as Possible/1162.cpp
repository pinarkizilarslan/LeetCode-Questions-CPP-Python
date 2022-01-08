class Solution
{
public:
  int maxDistance(vector<vector<int>> &grid)
  {
    int row = grid.size();
    int column = grid[0].size();

    int Y = row - 1;
    int X = column - 1;

    vector<vector<int>> values(row, vector<int>(column, INT_MAX));

    queue<pair<int, int>> queue;
    for (int y = 0; y != row; y++)
    {
      for (int x = 0; x != column; x++)
      {
        if (grid[y][x] == 0 && ((y && grid[y - 1][x]) || (y != Y && grid[y + 1][x]) || (x && grid[y][x - 1]) || (x != X && grid[y][x + 1])))
        {
          queue.push({y, x});
          values[y][x] = 1;
        }
      }
    }
    if (queue.empty())
    {
      return -1;
    }
    int w = 0;
    while (!queue.empty())
    {
      w++;
      int n = queue.size();
      while (n--)
      {
        auto [y, x] = queue.front();
        queue.pop();

        if (y && grid[y - 1][x] == 0 && values[y - 1][x] > w)
        {
          queue.push({y - 1, x});
          values[y - 1][x] = w;
        }
        if (y != Y && grid[y + 1][x] == 0 && values[y + 1][x] > w)
        {
          queue.push({y + 1, x});
          values[y + 1][x] = w;
        }

        if (x && grid[y][x - 1] == 0 && values[y][x - 1] > w)
        {
          queue.push({y, x - 1});
          values[y][x - 1] = w;
        }
        if (x != X && grid[y][x + 1] == 0 && values[y][x + 1] > w)
        {
          queue.push({y, x + 1});
          values[y][x + 1] = w;
        }
      }
    }
    return w;
  }
};