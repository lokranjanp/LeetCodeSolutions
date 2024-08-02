class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones == 0) return 0;


        vector<int> extend(nums.begin(), nums.end());
        extend.insert(extend.end(), nums.begin(), nums.end());


        int zeroes = count(extend.begin(), extend.begin() + ones, 0);
        int min_zeroes = zeroes;


        for (int i = ones; i < extend.size(); ++i) {
            if (extend[i] == 0) zeroes++;
            if (extend[i - ones] == 0) zeroes--;

            min_zeroes = min(min_zeroes, zeroes);
        }

        return min_zeroes;
    }
};
