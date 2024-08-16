class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int mini = arr[0][0];
        int maxi = arr[0].back();

        int max_dist = 0;

        for(int i = 1; i<arr.size(); ++i)
        {
            max_dist = max(max_dist , abs(arr[i].back() - mini));
            max_dist = max(max_dist, abs(maxi - arr[i].front()));
            mini = min(mini, arr[i].front());
            maxi = max(maxi, arr[i].back());
        }

        return max_dist;
    }
};