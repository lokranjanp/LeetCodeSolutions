class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char,char> map1,map2;
        for(int i = 0; i<s.size(); i++)
        {
            if(map1.count(s[i])==0 && map2.count(t[i])==0)
            {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else if(map1.count(s[i])==1 && map2.count(t[i])==1)
            {
                if(map1[s[i]]==t[i] && map2[t[i]]==s[i])
                    continue;
                else
                    return false;
            }
            else
                return false;
        }
        return true;
                
        }
};