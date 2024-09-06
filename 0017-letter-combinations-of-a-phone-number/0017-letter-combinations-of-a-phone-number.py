class Solution:    
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        mapp = {
            '2':'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }

        res = []

        def helper(idx, comb, res, digits, mapp):
            if idx == len(digits):
                res.append(comb)
                return

            for letter in mapp[digits[idx]]:
                helper(idx+1, comb+letter, res, digits, mapp)

        helper(0, "", res, digits, mapp)
        return res