class Solution:
    def maximumSumQueries(self, nums1: List[int], nums2: List[int], queries: List[List[int]]) -> List[int]:
        p = sorted(zip(nums1,nums2), reverse=True)
        idxq = sorted([(x,y,i) for i, (x,y) in enumerate(queries)],reverse=True)

        n = len(queries)
        res = [-1] * n
        st = []
        j = 0
        
        for x,y, qi, in idxq:
            while j < len(p) and p[j][0] >= x:
                a,b = p[j]
                s = a+b

                while st and st[-1][1] <= s: st.pop()
                if not st or st[-1][0] < b: st.append((b,s))
                j += 1
            k = bisect_left(st,(y,-1))
            if k < len(st): res[qi] = st[k][1]
        return res
