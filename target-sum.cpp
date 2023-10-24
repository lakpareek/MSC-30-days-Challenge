class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for(auto &it : nums) 
            sum += it;

        if((sum - target) % 2 != 0 || (sum - target) < 0)
            return 0;
        
        target = (sum - target) / 2;
        
        int dp[n + 1][target + 1];

        for(int i = 0; i <= n; i++) 
            dp[i][0] = 1;

        for(int i = 1; i <= target; i++) 
            dp[0][i] = 0;

        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= target; j++)
                if(nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
        return dp[n][target];
    }
};
