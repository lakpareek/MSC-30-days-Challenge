class Solution {
public:
    // int f(vector<vector<int>>& triangle, int m, int n, vector<vector<int>> &dp){
    //     if( m == triangle.size() - 1){
    //         return dp[m][n] = triangle[m][n];
    //     }
    //     if(dp[m][n] != -1){
    //         return dp[m][n];
    //     }
    //     int straight = triangle[m][n] + f(triangle, m+1, n, dp);
    //     int diagonal = triangle[m][n] + f(triangle, m+1, n+1, dp);
    //     return dp[m][n] = min(straight, diagonal);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        //return f(triangle, m-1, n-1, dp);
        for(int i = 0; i<n; i++){
            dp[m-1][i] = triangle[m-1][i];
        }
        for(int i = m-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                int straight = triangle[i][j] +  dp[i+1][j];
                int diagonal = triangle[i][j] +  dp[i+1][j+1];  
                dp[i][j] = min(straight, diagonal);
            }
        }
        return dp[0][0];
    }
};
