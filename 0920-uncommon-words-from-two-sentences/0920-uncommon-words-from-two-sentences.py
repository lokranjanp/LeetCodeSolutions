class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        words_s1 = s1.split()
        words_s2 = s2.split()

        total = words_s1 + words_s2

        wordcount = Counter(total)

        ans = []

        for word in wordcount:
            if wordcount[word] == 1:
                ans.append(word)

        return ans
