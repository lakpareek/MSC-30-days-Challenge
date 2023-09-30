class Solution {
public:
    void bfs(unordered_map<int, list<int>> adjList, int node, unordered_map<int, bool> &visited){
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto i : adjList[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i<isConnected.size(); i++){
            for(int j = 0; j<isConnected[0].size(); j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        unordered_map<int, bool> isVisited;
        int count = 0;
        for(int i = 0; i<isConnected.size(); i++){
            if(!isVisited[i]){
                bfs(adj, i, isVisited);
                count++;
            }
        }
        return count;
    }
};
