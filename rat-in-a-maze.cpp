class Solution{
    public:
    bool isSafe(int x, int y, vector<vector<int>> &m, vector<vector<bool>> &visited){
        int n = m.size();
        if(x<n && y<n){
            if(m[x][y] == 1 && visited[x][y] == false){
                return true;
            }
        }
        return false;
    }
    void helper(int x, int y, vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<bool>> &visited, string path){
        if(x == n - 1 && y == n - 1){
            ans.push_back(path);
            visited[x][y] = false;
            return ;
        }
        visited[x][y] = true;
        if(isSafe(x+1, y, m, visited)){
            helper(x+1, y, m, n, ans, visited, path + 'D');
            path.pop_back();
        }
        if(isSafe(x-1, y, m, visited)){
            helper(x-1, y, m, n, ans, visited, path + 'U');
            path.pop_back();
        }
        if(isSafe(x, y+1, m, visited)){
            helper(x, y+1, m, n, ans, visited, path + 'R');
            path.pop_back();
        }
        if(isSafe(x, y-1, m, visited)){
            helper(x, y-1, m, n, ans, visited, path + 'L');
            path.pop_back();
        }
        visited[x][y] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n,0));
        string path = "";
        int x = 0;
        int y = 0;
        helper(x, y, m, n, ans, visited, path);
        return ans;
    }
};
