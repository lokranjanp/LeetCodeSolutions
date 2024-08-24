class Solution {
private:
    void helper(int open, int close, vector<string>&ans, string str)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(str);
            return;
        }

        if(open > 0)
            helper(open-1, close, ans, str+"(");
        if(close > 0 && close>open)
            helper(open, close-1, ans, str+")");
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr = "";

        helper(n, n, ans, curr);
        return ans;
    }
};