class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;

        string constr = goal + goal;
        return constr.find(s)!=string::npos;
    }
};