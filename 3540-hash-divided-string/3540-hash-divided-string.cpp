class Solution {
public:
    string stringHash(string s, int k) {
        string res = "";

        int n = s.size();

        for(int i = 0, alphasum = 0; i<n; ++i)
        {
            alphasum += s[i] - 'a';

            if((i+1)%k == 0)
            {
                res += ('a' + (alphasum%26));
                alphasum = 0;
            }
        }

        return res;
    }
};