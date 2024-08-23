class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>freq_s;
        vector<int>freq_t;

        unordered_map<char, int> freq_str_s;
        unordered_map<char, int> freq_str_t;

        for(auto c : s)
            freq_str_s[c]++;

        for(auto c : t)
            freq_str_t[c]++;

        for(auto x : freq_str_s)
            freq_s.push_back(x.second);

        for(auto x : freq_str_t)
            freq_t.push_back(x.second);

        sort(freq_s.begin(), freq_s.end());
        sort(freq_t.begin(), freq_t.end());

        return freq_s == freq_t;
    }
};