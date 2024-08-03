class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> freq;

        for(int n : target)
            freq[n]++;

        for(int n : arr)
        {
            if(freq.find(n) == freq.end())
                return false;

            if(freq[n] == 0)
                return false;

            else
                freq[n]--;
        }

        return true;
    }
};