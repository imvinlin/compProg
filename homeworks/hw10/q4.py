class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        pre = [0]
        for num in nums:
            pre.append(pre[-1]+num)

        s = SortedList()
        res = 0
        for val in pre:
            res += s.bisect_right(val-lower) - s.bisect_left(val-upper)
            s.add(val)
        return res
