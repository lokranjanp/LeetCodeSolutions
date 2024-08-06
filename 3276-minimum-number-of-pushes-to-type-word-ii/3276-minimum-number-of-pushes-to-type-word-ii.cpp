class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;

        for(char c : word)
            freq[c]++;

        priority_queue<int>pq;

        for(const auto it: freq)
            pq.push(it.second);

        int res = 0;
        int pos = 0;
        
        while(!pq.empty())
        {
            res += (pos/8 + 1)*pq.top();
            pq.pop();
            pos++;
        }

        return res;
    }
};