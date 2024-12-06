class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        minheap = nums[:k]
        heapify(minheap)

        for num in nums[k:]:
            if num > minheap[0]:
                heappop(minheap)
                heappush(minheap, num)

        return minheap[0]