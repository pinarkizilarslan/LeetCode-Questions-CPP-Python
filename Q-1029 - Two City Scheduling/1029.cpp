bool compare(vector<int>& a, vector<int>& b){
    return a[0]-a[1] < b[0]-b[1];
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int minSum=0;
        sort(costs.begin(), costs.end(), compare);        
        
        for(int i=0;i<costs.size();i++){
            if(i<costs.size()/2)
                minSum+=costs[i][0];
            else
                minSum+=costs[i][1];
        }
        
        return minSum;
    }
};