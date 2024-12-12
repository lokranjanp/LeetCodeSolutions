class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        nums = [-num for num in gifts]
        heapify(nums)

        while k:
            temp = math.isqrt(-heappop(nums))
            heappush(nums, -temp)
            k -= 1

        return -sum(nums)