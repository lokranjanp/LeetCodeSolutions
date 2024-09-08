class Solution {
public:
    string reverseVowels(string s) {
        set<char>vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string ans = s;
        int left = 0, right = s.size()-1;

        while(left<right)
        {
            if(vowels.find(ans[left])!=vowels.end() && vowels.find(ans[right])!=vowels.end())
            {
                swap(ans[left], ans[right]);
                left++;
                right--;
            }

            else if(vowels.find(ans[left])!=vowels.end())
                right--;
            else
                left++;
        }

        return ans;
    }
};