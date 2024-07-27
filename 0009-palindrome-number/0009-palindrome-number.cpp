class Solution {
public:
    bool isPalindrome(int x) {

        long long int old_num = x;
        long long int new_num = 0;
        while(x>0)
        {
            int dig = x%10;
            new_num = (new_num * 10) + dig;
            x = x/10;
        }

        return new_num == old_num;
    }
};