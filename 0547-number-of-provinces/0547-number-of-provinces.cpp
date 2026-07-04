class Solution {
private: 
    void dfs(int node, vector<int> adjlst[], vector<int>& vis){
        vis[node] = 1;
        for(auto it : adjlst[node]){
            if(!vis[it]){
                dfs(it, adjlst, vis);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> adjlst[v];
        for(int i = 0; i < v; i++){
            for(int j = 0;j < v; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjlst[i].push_back(j);
                    adjlst[j].push_back(i);
                }
            }
        }
        vector<int> vis(v, 0);
        int count = 0;
        for(int i = 0; i < v; i++){
            if(!vis[i]){
                count++;
                dfs(i, adjlst, vis);
            }
        }
        return count;
    }
};