//Recucrsion(brute Force Sub-Optimal Code)
class Solution {
public:
    int fib(int n) {
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }

        int ans = fib(n-1) +fib(n-2);
        return ans;
    }
};

//using memoization
class Solution {
public:
    int helper(int n, vector<int> &dp){
        if(n <= 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};

//using tabulation this time

class Solution {
public:
    
    int fib(int n) {
        int prev1 = 0;
        int prev2 = 1;
        int curr = 0;
        for(int i = 2; i<=n; i++){
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        if(n == 1){
            return 1;
        }
        return curr;
    }
};
