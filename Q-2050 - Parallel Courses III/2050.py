class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        
        graph = defaultdict(set)
        degree = defaultdict(int)
        for i, j in relations:
            degree[j-1] += 1
            graph[i-1].add(j-1)
            
        count = 0        
        prev = defaultdict(int)
        
        queue = [(time[x], x) for x in range(n) if degree[x] == 0]
        heapify(queue)
        
        while(queue):
            temp, course = heappop(queue)
            count += 1
            if(count == n):
                return temp
            for nei in graph[course]:
                degree[nei] -= 1
                prev[nei] = max(prev[nei], temp)
                if(degree[nei] == 0):
                    heappush(queue, (prev[nei] + time[nei], nei))