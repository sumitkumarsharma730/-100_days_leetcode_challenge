// Time complexity : O((N+E)α(N))
// where α(N) is the inverse Ackermann function, which is effectively constant in practice.
// Space complexity : O(N)
// DSU stands for Disjoint Set Union.

class Solution {
public:
    vector<int> par;

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]) ;
    }

    void uunion(int u, int v){   // connecting u and v of an edge
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;
        else{
            par[pv] = pu;
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        par.resize(n);
        for(int i=0; i<n; i++) par[i] = i; 

        vector<int> count(n); // to count no of edges in a connected sub-graph
        vector<int> size(n); // to count no of nodes connected to parent of subgraph

        int ans = 0;

        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int pu = find(u);
            int pv = find(v);

            uunion(pu,pv) ; 
        }

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];

            int pu = find(u);

            count[pu]++;
        }

        for(int i=0; i<n; i++){
            int papa = find(i) ;
            size[papa] ++ ;
        }

        for(int i=0; i<n; i++){
            if(size[i] == 0) continue ;
            int k = size[i];
            if(count[i] == (k*(k-1))/2) ans++;
        }

        return ans ;
    }
};