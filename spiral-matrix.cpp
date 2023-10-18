class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int maxrow= matrix.size();
        int maxcol = matrix[0].size();
        int count = 0;
        int TotSize = maxrow*maxcol;
        int endcol = maxcol-1;
        int endrow = maxrow - 1;
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(TotSize>count){
            for(int n = j; TotSize>count && n<=endcol; n++){
                ans.push_back(matrix[i][n]);
                count++;
            }
            i++;
            for(int n = i; TotSize>count && n<=endrow; n++){
                ans.push_back(matrix[n][endcol]);
                count++;
            }
            endcol--;
            for(int n = endcol; TotSize>count && n>=j; n--){
                ans.push_back(matrix[endrow][n]);
                count++;
            }
            endrow--;
            for(int n = endrow; TotSize>count && n>=i; n--){
                ans.push_back(matrix[n][j]);
                count++;
            }
            j++;
        }
        return ans;   
    }
};