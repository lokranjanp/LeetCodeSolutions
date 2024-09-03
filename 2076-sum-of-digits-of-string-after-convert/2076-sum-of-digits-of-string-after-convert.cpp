class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char c : s)
            num += to_string(c - 'a' +1);

        while(k)
        {
            int res = 0;
            for(char &c : num)
                res += c - '0';

            num = to_string(res);
            k--;
        }
        return stoi(num);
    }
};