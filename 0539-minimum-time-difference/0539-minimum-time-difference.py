class Solution:
    def findMinDifference(self, timepoints: List[str]) -> int:
        res = []

        for time in timepoints:
            hour = time[:2]
            minutes = time[3:]

            res.append(int(hour)*60 + int(minutes))

        res.sort()
        ans = 24 * 60

        for i in range(len(res) -1):
            ans = min(ans, res[i+1]-res[i])

        return min(ans, 24*60-res[len(res)-1]+res[0])