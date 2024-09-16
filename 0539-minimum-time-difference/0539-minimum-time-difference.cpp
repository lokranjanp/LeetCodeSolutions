class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int> res(time.size());

        for(int i = 0; i<time.size(); i++)
        {
            string curr = time[i];

            int hour = stoi(curr.substr(0,2));
            int mins = stoi(curr.substr(3));

            res[i] = (hour*60)+mins;
        }

        sort(res.begin(), res.end());

        int ans = 60 * 24;

        for(int i = 0; i<res.size()-1; i++)
            ans = min(ans, res[i+1]-res[i]);

        return min(ans, 24*60-res[res.size()-1]+res[0]);
    }
};