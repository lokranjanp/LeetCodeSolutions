class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans = 0
        curr = 0
        for alt in gain:
            ans = max(ans, curr)
            curr = curr + alt

        if curr>ans:
            ans = curr
            
        return ans