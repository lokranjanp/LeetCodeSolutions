class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>nums={2, 3, 5};
        priority_queue<long, vector<long>, greater<long>>heap;
        unordered_set<long>vis;

        heap.push(1);
        vis.insert(1);

        long curr;
        for(int i = 0; i<n; ++i)
        {
            curr = heap.top();
            heap.pop();
            for(int n:nums)
            {
                long ugly = curr * n;
                if(vis.find(ugly) == vis.end())
                {
                    heap.push(ugly);
                    vis.insert(ugly);
                }
            }
        }
        return int(curr);
    }
};