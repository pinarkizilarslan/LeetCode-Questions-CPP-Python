class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        
        sumLeft=0
        sumRight=0
        
        for i in range(len(nums)):
            sumRight+=nums[i]
        
        for i in range(len(nums)):
            sumRight-=nums[i]
            if(sumLeft==sumRight) :                
                return i
            sumLeft+=nums[i]
                
        return -1