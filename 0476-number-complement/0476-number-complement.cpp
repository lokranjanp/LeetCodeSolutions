class Solution {
public:
    int findComplement(int num) {
        int i = 0, ans = 0;

        while(num){
            int res = num & 1;
            if(!res)
                ans += pow(2, i);
            num = num>>1;
            i++;
        }
        return ans;
    }
};