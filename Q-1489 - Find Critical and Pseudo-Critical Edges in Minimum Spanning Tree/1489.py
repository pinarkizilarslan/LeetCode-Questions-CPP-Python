class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj = [[] for i in range(n)]
        parent = [i for i in range(n)]
        tree = list()        
        critical = list()
        notcritical = list()
        level = [1] * n 
        
        def find(i):
            if(parent[i] == i):
                return i
            parent[i] = find(parent[i])
            return parent[i]

        def union(pu, pv):
            if(level[pu] > level[pv]):
                parent[pv] = pu
            elif(level[pu] < level[pv]):
                parent[pu] = pv
            else:
                parent[pv] = pu
                level[pv] += 1

        def path(adj, nodeweight, v, stack, vis):
            u = nodeweight[0]
            vis[u] = 1
            stack.append(nodeweight)
            if u == v:
                return True
            for child in adj[u]:
                if not(vis[child[0]]):
                    if(path(adj, child, v, stack, vis)):
                        return True
            stack.pop(-1)

        edges = [(u, v, w, i) for i, (u,v,w) in enumerate(edges)]
        edges.sort(key = lambda x: x[2])
        e = len(edges)
        count = 0
        i = 0
        while(i < e):
            if(count == n-1 and edges[i][2] > last): 
                break
            (u, v, w, ind) = edges[i]
            urep = find(u)
            vrep = find(v)
            if(urep != vrep):
                adj[u].append((v, w, ind))
                adj[v].append((u, w, ind))
                tree.append(ind)
                last = w
                count += 1
                union(urep, vrep)
            else:
                if(last == w):
                    stack = list()
                    vis = [0] * n
                    path(adj, (u,0,n) , v, stack, vis) 
                    for half in stack:
                        if(half[1] == w):
                            if(half[2] not in notcritical):
                                notcritical.append(half[2]) 
                            if(ind not in notcritical):
                                notcritical.append(ind)        
            i+= 1
        for i in tree:
            if(i not in notcritical):
                critical.append(i)
        return [critical, notcritical]
