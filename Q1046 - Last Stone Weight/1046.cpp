class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(),stones.end());
        while(true){
            if(stones.size()<=1)
                break;
            int y = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int x = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            if(x<y){
                stones.push_back(y-x);
                push_heap(stones.begin(), stones.end()); 
            }
        }

        if(stones.size()==1)
            return stones[0];
        return 0;
    }
};