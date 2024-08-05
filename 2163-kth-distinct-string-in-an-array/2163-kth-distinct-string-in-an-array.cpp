class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for(auto &v : arr)
            ++count[v];

        for(auto &v : arr)
            if(count[v] == 1)
            {
                --k;
                if(k == 0)
                    return v;
            }
        return "";
    }
};