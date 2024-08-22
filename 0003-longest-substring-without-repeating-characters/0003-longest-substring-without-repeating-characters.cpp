class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        int left = 0;
        unordered_map<char,int>mpp;

        for(int right = 0; right<n; right++)
        {
            if(mpp.count(s[right]) == 0 || mpp[s[right]] < left)
            {
                mpp[s[right]] = right;
                maxlen = max(maxlen, right - left + 1);
            }
            else{
                left = mpp[s[right]]+1;
                mpp[s[right]] = right;
            }

        }
        return maxlen;
    }
};