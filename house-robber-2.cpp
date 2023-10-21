class Solution {
public:
    int f(vector<int>& nums, int chosenIndex, int endIndex, vector<int>& dp) {
        if (chosenIndex >= endIndex) {
            return 0;
        }
        
        if (dp[chosenIndex] != -1) {
            return dp[chosenIndex];
        }
        
        int robCurrentHouse = nums[chosenIndex] + f(nums, chosenIndex + 2, endIndex, dp);
        int skipCurrentHouse = f(nums, chosenIndex + 1, endIndex, dp);
        
        int ans = max(robCurrentHouse, skipCurrentHouse);
        dp[chosenIndex] = ans;
        
        return ans;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        

        return max(f(nums, 0, nums.size() - 1, dp1), f(nums, 1, nums.size(), dp2));
    }
};
