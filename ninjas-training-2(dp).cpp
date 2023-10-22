// int f(int day, int last, vector<vector<int>> points, vector<vector<int>> &dp)
// {
//     if(day == 0){
//         int maxi = 0;
//         for(int i = 0; i<3; i++){
//             if(i!=last){
//                 maxi = max(maxi, points[0][i]);
//             }
//             dp[day][i] = maxi;

//         }
//         return maxi;
//     }
//     if(dp[day][last] != -1){
//         return dp[day][last];
//     }
//     int maxi = 0;
//     for(int i = 0; i<3; i++){
//         if(i!=last){
//             maxi = max(maxi, points[day][i] + f(day-1, i, points, dp));
            
//         }
//     }
//     return dp[day][last] = maxi;
// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     // Write your code here.
//     vector<vector<int>> dp(n, vector<int>(4, -1));
//     return f(n-1, 3, points, dp);
// }

//-------------------------------------------------------------------Optimal solution using tabulation----------------------------------------------------------------------------------------


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> prev(4, -1);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][2], points[0][0]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for(int day = 1; day<n; day++){
        vector<int> curr(4, -1);
        for(int lastTask = 0; lastTask<4; lastTask++){
            curr[lastTask] = 0;
            for(int currentTask = 0; currentTask<3; currentTask++){
                if(currentTask != lastTask){
                    curr[lastTask] = max(curr[lastTask], points[day][currentTask] + prev[currentTask]);
                }
            }
        }
        prev = curr;
    }
    return prev[3];
}
