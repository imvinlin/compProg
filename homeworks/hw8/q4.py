class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        rows,cols = len(seats), len(seats[0])

        valid_masks = []
        for r in range(rows):
            av = 0
            for c in range(cols):
                if seats[r][c] == '.':
                    av |= (1 << c)

            row_masks = []
            for mask in range(1 << cols):
                if (mask & av) != mask: continue
                if mask & (mask << 1): continue
                row_masks.append(mask)
            valid_masks.append(row_masks)

        dp = {0:0}
        for r in range(rows):
            ndp = {}

            for curr in valid_masks[r]:
                students = curr.bit_count()

                for prev, prev_best in dp.items():
                    if curr & (prev << 1): continue
                    if curr & (prev >> 1): continue

                    ndp[curr] = max(ndp.get(curr,0), prev_best + students)
            dp = ndp
        return max(dp.values(),default=0)
