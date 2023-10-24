class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = INT_MAX;
        vector<int> dp(amount + 1, -1);
        int x = findMinCoins(coins, amount, dp);
        return x == INT_MAX ? -1 : x;
    }
    
    int findMinCoins(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }
        
        if (amount < 0) {
            return INT_MAX;
        }
        
        if (dp[amount] != -1) {
            return dp[amount];
        }
        
        int minCoins = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int result = findMinCoins(coins, amount - coins[i], dp);
            if (result != INT_MAX) {
                minCoins = min(minCoins, result + 1);
            }
        }
        
        dp[amount] = minCoins;
        return minCoins;
    }
};
