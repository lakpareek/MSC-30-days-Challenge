class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        if(obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        vector<int> prev(n, 0);
        for(int i = 0; i<m; i++){
            vector<int> curr(n , 0);
            for(int j = 0; j<n; j++){
                if(j == 0 && i == 0){
                    prev[0] = 1;
                    curr[0] = 1;
                }
                else if(obstacleGrid[i][j] == 1){
                    curr[j] = -1;
                }
                else{
                    if(i>0){
                        if(prev[j] != -1){
                            curr[j] += prev[j];
                        }
                    }
                    if(j>0){
                        if(curr[j-1] != -1){
                            curr[j] += curr[j-1];
                        }
                    }
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
