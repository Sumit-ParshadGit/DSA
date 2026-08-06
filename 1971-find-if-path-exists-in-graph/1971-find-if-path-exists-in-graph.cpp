class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        if(src==dest)return 1;
        vector<bool>vis(n,0);
        queue<int>q;
        vector<vector<int>>adj(n);
        for(auto&el:edges){
            int u = el[0];
            int v = el[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            vis[f] = 1;
            for(auto&u:adj[f]){
                if(u==dest)return 1;
                if(!vis[u]){q.push(u);
                vis[u] = 1;}
            }
        }return 0;
    }
};