class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        result = []
        tempResult = []

        def recursive(node):
            if node == len(graph)-1:
                result.append(tempResult.copy())
                return

            for i in graph[node]:
                tempResult.append(i)
                recursive(i)
                tempResult.pop()

        tempResult.append(0)
        recursive(0)
        return result