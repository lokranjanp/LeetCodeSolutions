class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {
        if(n==0)
            return true;

        int place = 1;

        for(int i = 0; i<flower.size(); i++)
        {
            if(flower[i] == 0)
                place++;
            else
                place = 0;

            if(place == 3)
            {
                n--;
                place = 1;
            }
            else if(place == 2 && i == flower.size()-1)
                n--;

            if(n==0)
                return true;
        }

        return n==0;
    }
};