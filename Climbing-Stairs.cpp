//Brute force TLE Solution

class Solution {
public:
    int climbStairs(int n) {
        if(n < 0)
        return 0;
    
    if(n == 0)
        return 1;
    
    int ans = climbStairs(n-1) 
        + climbStairs(n-2);
    
    return ans;
    }
};

//using Memoization
class Solution {
public:
    int helper(int n, vector<int> &dp) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};

// using tabulation
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        int prev1 = 1;
        int prev2 = 2;
        int curr = 0;
        for(int i = 3; i<=n; i++){
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }
};
