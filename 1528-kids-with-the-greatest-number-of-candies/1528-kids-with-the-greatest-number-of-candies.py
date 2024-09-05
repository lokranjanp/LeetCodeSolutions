class Solution:
    def kidsWithCandies(self, candies: List[int], extra: int) -> List[bool]:
        ans = []
        maxcandies = max(candies)

        i = 0
        for i in range(0, len(candies)):
            if candies[i] + extra >= maxcandies:
                ans.append(True)
            else:
                ans.append(False)

        return ans