#include <bits/stdc++.h>

int helper(vector<int> &heights, int currentIndex, vector<int> &dp) {
    if (currentIndex == 0) {
        return 0;
    }
    if(dp[currentIndex] != -1){
        return dp[currentIndex];
    }
    int ans = INT_MAX;

    if (currentIndex >= 1) {
        int oneStep = helper(heights, currentIndex - 1, dp) + abs(heights[currentIndex] - heights[currentIndex - 1]);
        ans = min(ans, oneStep);
    }

    if (currentIndex >= 2) {
        int twoStep = helper(heights, currentIndex - 2, dp) + abs(heights[currentIndex] - heights[currentIndex - 2]);
        ans = min(ans, twoStep);
    }
    dp[currentIndex] = ans;
    return ans;
}

int frogJump(int n, vector<int> &heights) {
    if (n <= 0) {
        return 0;
    }
    vector<int> dp(n, -1);
    return helper(heights, n - 1, dp);
}
