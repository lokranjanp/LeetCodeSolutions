class Solution:
    def isPrefixOfWord(self, sentence: str, searchw: str) -> int:
        words = sentence.split(" ")
        for i, word in enumerate(words, start = 1):
            if word.startswith(searchw):
                return i

        return -1