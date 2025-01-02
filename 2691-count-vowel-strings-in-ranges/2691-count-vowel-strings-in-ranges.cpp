class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n+1, 0);
        unordered_set<char> vchars = {'a', 'e', 'i', 'o', 'u'};

        for(int i =0; i<n; i++)
        {
            pref[i+1] = pref[i];
            if (vchars.count(words[i].front()) && vchars.count(words[i].back()))
                pref[i+1]++;
        }

        vector<int>ans;
        for(auto &q : queries)
        {
            int left = q[0], right = q[1];
            ans.push_back(pref[right+1]-pref[left]);
        }

        return ans;
    }
};