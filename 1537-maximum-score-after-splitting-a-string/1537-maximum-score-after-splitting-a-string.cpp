class Solution {
public:
    int maxScore(string s) {
        int most = 0;
        int count = 0;

        int ones = 0;
        for(char c : s)
            if (c=='1')
                ones++;

        for(int i = 0; i<s.size()-1; i++)
        {
            if(s[i] == '0')
                most++;
            else
                ones--;

            count = max(count, most + ones);
        }

        return count;
    }
};