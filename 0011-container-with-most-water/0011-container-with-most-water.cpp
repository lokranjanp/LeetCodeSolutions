class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int n = height.size();
        int right = n-1;
        int maxarea = 0;

        while(left<=right)
        {
            int minh = min(height[left], height[right]);
            int area = minh * (right - left);

            maxarea = max(maxarea, area);

            if(height[left] < height[right])
                left++;
            
            else if(height[right] < height[left])
                right--;

            else{
                left++;
                right--;
            }

        }
        return maxarea;
    }
};