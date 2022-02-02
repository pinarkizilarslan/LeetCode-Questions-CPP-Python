class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent = [-1] * (len(edges)+1)
        
        def find(i):
            if(parent[i] < 0):
                return i
            
            parent[i] = find(parent[i])
            return parent[i]
        
        for i,j in edges:
            s1 = find(i)
            s2 = find(j)
            
            if(s1 == s2):
                return(i,j)
            else:
                if(parent[s1]<parent[s2]):
                    parent[s1] += parent[s2]
                    parent[s2] = s1
                else:
                    parent[s2] += parent[s1]
                    parent[s1] = s2