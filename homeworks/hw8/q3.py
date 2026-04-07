class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
            graph = [[] for _ in range(n)]
            for u,v in connections:
                graph[u].append(v)
                graph[v].append(u)

            disc = [-1] * n
            low = [-1] * n
            timer = count()
            bridges = []

            def dfs(u,par):
                disc[u] = low[u] = next(timer)

                for v in graph[u]:
                    if v == par: continue

                    if disc[v] == -1:
                        dfs(v,u)
                        low[u] = min(low[u],low[v])

                        if low[v] > disc[u]:
                            bridges.append([u,v])
                    else:
                        low[u] = min(low[u],disc[v])
            dfs(0,-1)
            return bridges
