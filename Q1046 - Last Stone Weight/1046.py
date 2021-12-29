class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        length = len(stones)
        while length > 1:
            stones = sorted(stones)
            if stones[-1] == stones[-2]:
                stones = stones[0:length-2]
            else:
                stones[-2] = abs(stones[-1] - stones[-2])
                stones = stones[0:length-1]
            length = len(stones)

        if stones == []: return 0
        else: return stones[0]