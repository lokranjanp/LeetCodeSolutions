class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int s1 = s.length(), t1 = t.length();

        while(i<s1 && j<t1)
        {
            if(s[i] == t[j])
                i++;
            j++;
        }
        return i==s1;
    }
};