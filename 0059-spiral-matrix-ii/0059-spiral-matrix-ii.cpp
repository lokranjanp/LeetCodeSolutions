class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int total = n * n;

        int frow = 0;
        int lrow = n-1;
        int fcol = 0;
        int lcol = n-1;

        int count = 0;

        vector<vector<int>>res(n, vector<int>(n, 0));

        while(count < total)
        {
            for(int i = fcol; count<total && i<=lcol; i++)
                res[frow][i] = ++count;

            frow++;

            for(int i = frow; count<total && i<=lrow; i++)
                res[i][lcol] = ++count;

            lcol--;

            for(int i = lcol; count<total && i>=fcol; i--)
                res[lrow][i] = ++count;

            lrow--;

            for(int i = lrow; count<total && i>=frow; i--)
                res[i][fcol] = ++count;

            fcol++;
        }

        return res;
    }
};