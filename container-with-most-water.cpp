class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int j = height.size() - 1;
        int i = 0;
        while(i<j){
            if(height[i]<height[j]){
                ans = max(ans, height[i]*(j-i));
                i++;
            }
            else{
                ans = max(ans, height[i]*(j-i));
                j--;
            }
        }
        return ans;
    }
};