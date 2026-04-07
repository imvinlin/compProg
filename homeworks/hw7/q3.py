class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        bset = set()
        for b in blocked:
            bset.add(tuple(b))
        
        limit = (len(blocked) * (len(blocked)-1)) // 2

        def bfs(start, end):
            q = deque([start])
            seen = set([start])

            while q:
                x, y = q.popleft()

                if (x, y) == end:
                    return True

                if len(seen) > limit:
                    return True
                
                dirs = [(1,0),(-1,0),(0,1),(0,-1)]
                for dx,dy in dirs:
                    nx,ny = x+dx, y+dy

                    if not (0 <= nx < 10**6 and 0 <= ny < 10**6):
                        continue

                    if (nx, ny) in bset or (nx, ny) in seen:
                        continue

                    seen.add((nx, ny))
                    q.append((nx, ny))
            return False

        return bfs(tuple(source),tuple(target)) and bfs(tuple(target),tuple(source))
