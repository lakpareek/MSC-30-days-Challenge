class Solution {
public:
    int f(vector<vector<int>>& matrix, int m, int n) {
        if (m < 0 || n < 0 || n >= matrix[0].size()) {
            return 100000;
        }
        int u = matrix[m][n] + f(matrix, m - 1, n);
        int ld = matrix[m][n] + f(matrix, m - 1, n - 1);
        int rd = matrix[m][n] + f(matrix, m - 1, n + 1);
        return min(u, min(ld, rd));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minSum = INT_MAX;
        
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, f(matrix, m - 1, j));
        }

        return minSum;
    }
};
