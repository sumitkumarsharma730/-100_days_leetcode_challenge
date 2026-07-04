class Solution {
private: 
    void dfs(unordered_map<int, list<pair<int, int>>>& adj, vector<int>& visited, queue<int>& q, int& ans){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                ans = min(ans, it.second);
                if(!visited[it.first]){
                    visited[it.first] = 1;
                    q.push(it.first);
                }
            }
        }
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<pair<int, int>>> adj;
        vector<int> visited(n+1, 0);
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        int ans = INT_MAX;
        dfs(adj, visited, q, ans);
        return ans;
    }
};