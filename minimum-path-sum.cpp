class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, -1);
        for(int i = 0; i<m; i++){
            vector<int>curr(n, -1);
            for(int j = 0; j<n; j++){
                if(i==0&&j==0){
                    prev[0] = grid[0][0];
                    curr[0] = grid[0][0];
                }else{
                    int up = grid[i][j];
                    int left = grid[i][j];
                    if(i>0){
                        up += prev[j];
                    }else{
                        up = 201;
                    }
                    if(j>0){
                        left += curr[j-1];
                    }else{
                        left = 201;
                    }
                    curr[j] = min(left, up);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
