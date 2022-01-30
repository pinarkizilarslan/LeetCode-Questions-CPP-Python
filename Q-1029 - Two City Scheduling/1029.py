class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        
        minSum = 0
        costs = sorted(costs, key=lambda interval: interval[0] - interval[1])     
        
        for i in range(len(costs)):
            if(i<len(costs)/2) :
                minSum+=costs[i][0]
            else :
                minSum+=costs[i][1]        
        
        return minSum