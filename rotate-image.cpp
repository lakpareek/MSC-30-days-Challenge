class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        int row = 0;
        int col = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans[j][i] = v[i][j];
            }
        }
        return ans;
    }
    void reverse(vector<vector<int>>& v){
        int maxCol = v[0].size();
        for(int i = 0; i<v.size(); i++){
            int j = 0;
            while(j<maxCol - j - 1){
                swap(v[i][j], v[i][maxCol-1-j]);
                j++;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> tr = transpose(matrix);
        reverse(tr);
        matrix = tr;
    }
};