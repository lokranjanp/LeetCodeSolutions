class Solution {
public:
    void helper(int s,int k, int n, vector<int>&pos,vector<vector<int>>&ans)
    {
        if(pos.size() == k)
        {
            if(n==0)
            {
                ans.push_back(pos);
                return;
            }
        }

        for(int i = s; i<=9; i++)
        {
            // if(n-i<0)
            //     break;
            pos.push_back(i);
            helper(i+1,k,n-i,pos,ans);
            pos.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>>ans;
        vector<int>pos;
        helper(1,k,n,pos,ans);

        return ans;        
    }
};