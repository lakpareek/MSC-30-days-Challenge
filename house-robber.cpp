class Solution {
public:
    int helper(vector<int>& nums, int chosenIndex, vector<int>& dp){
        if(chosenIndex>=nums.size()){
            return 0;
        }
        if(dp[chosenIndex] != -1){
            return dp[chosenIndex];
        }
        int ans = max(helper(nums, chosenIndex + 2, dp), helper(nums, chosenIndex + 3, dp)) ;
        dp[chosenIndex] = ans + nums[chosenIndex];
        return dp[chosenIndex];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 2){
            return(max(nums[0], nums[1]));
        }
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 0){
            return 0;
        }
        vector<int> dp(nums.size(), -1);
        return max(helper(nums, 0, dp), helper(nums, 1, dp));
    }
};
