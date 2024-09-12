class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>freq(26,0);
        for(auto c : allowed)
            freq[c-'a']++;

        int count = 0;

        for(int i = 0; i<words.size(); i++)
        {
            string res = words[i];
            bool valid = true;
            for(int j = 0; j<res.length(); j++)
            {
                if(freq[res[j]-'a']==0)
                {
                    valid = false;
                    break;
                }
            }

            if(valid)
                count++;
        }

        return count;
    }
};