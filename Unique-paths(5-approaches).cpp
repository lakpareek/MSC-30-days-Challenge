//using recursion(non-optimal)
// class Solution {
// public:
//     void f(int m, int n, int &ans){
//         if(m == 0 && n == 0){
//             ans++;
//         }
//         if(m<0 || n<0){
//             return ;
//         }
//         f(m - 1, n, ans);
//         f(m, n - 1, ans);
//     }
//     int uniquePaths(int m, int n) {
//         int ans = 0;
//         f(m - 1, n - 1, ans);
//         return ans;
//     }
// };


//-----------------------------------------------------------------------------using recursion(non-optimal)---------------------------------------------------------------------------------------

// class Solution {
// public:
//     int f(int m, int n){
//         if(m == 0 && n == 0){
//             return 1;
//         }
//         if(m<0 || n<0){
//             return 0;
//         }
//         int up = f(m - 1, n);
//         int left = f(m, n - 1);
//         return up + left;
//     }
//     int uniquePaths(int m, int n) {
//         return f(m - 1, n - 1);
//     }
// };

//-----------------------------------------------------------------------------using memoization(sub-optimal)---------------------------------------------------------------------------------------
// class Solution {
// public:
//     int f(int m, int n, vector<vector<int>> &dp){
//         if(m == 0 && n == 0){
//             return 1;
//         }
//         if(m<0 || n<0){
//             return 0;
//         }
//         if(dp[m][n] != -1){
//             return dp[m][n];
//         }
//         int up = f(m - 1, n, dp);
//         int left = f(m, n - 1, dp);
//         return dp[m][n] = up + left;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n ,-1));
//         return f(m - 1, n - 1, dp);
//     }
// };
//-----------------------------------------------------------------------------using tabulation(sub-optimal)---------------------------------------------------------------------------------------
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n ,0));
//         for(int i = 0; i<m; i++){
//             for(int j = 0; j<n; j++){
//                 if(j == 0 && i == 0){
//                     dp[i][j] = 1;
//                 }
//                 else{
//                     if(i>0){
//                         dp[i][j] += dp[i-1][j];
//                     }
//                     if(j>0){
//                         dp[i][j] += dp[i][j-1];
//                     }
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };
//-----------------------------------------------------------------------------using tabulation with further space optimisation (optimal/BEST)---------------------------------------------------------------------------------------


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for(int i = 0; i<m; i++){
            vector<int> curr(n , 0);
            for(int j = 0; j<n; j++){
                if(j == 0 && i == 0){
                    prev[0] = 1;
                    curr[0] = 1;
                }
                else{
                    if(i>0){
                        curr[j] += prev[j];
                    }
                    if(j>0){
                        curr[j] += curr[j-1];
                    }
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
