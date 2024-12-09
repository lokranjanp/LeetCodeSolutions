class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        freqs = {}

        for i in arr:
            if i in freqs:
                freqs[i] += 1
            else:
                freqs[i] = 1

        return True if len(set(freqs.values())) == len(freqs.values()) else False
