class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;;
        int lowr = 0 , lowc = 0;
        int highr = matrix.size()-1;
        int highc = matrix[0].size()-1;

        while(lowr<= highr || lowc <= highc)
        {
            if(lowr<=highr)
            {
                for(int c = lowc; c<= highc; c++)
                    ans.push_back(matrix[lowr][c]);

                lowr++;
            }

            if(lowc<= highc)
            {
                for(int r = lowr; r<=highr; r++)
                    ans.push_back(matrix[r][highc]);
            }

            highc--;

            if(lowr<=highr)
            {
                for(int c = highc; c>= lowc; c--)
                    ans.push_back(matrix[highr][c]);

                highr--;
            }

            if(lowc<=highc)
            {
                for(int r = highr; r>= lowr; r--)
                    ans.push_back(matrix[r][lowc]);

                lowc++;
            }
        }

        return ans;
        
    }
};