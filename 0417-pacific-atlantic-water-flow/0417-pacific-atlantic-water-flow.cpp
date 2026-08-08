class Solution {
public:
    void dfs(vector<vector<int>>&he,int i,int j,int pre,vector<vector<int>>&vis){
        if(i<0||j<0||i>=he.size()||j>=he[0].size())return ;
        if(vis[i][j]||pre>he[i][j])return ;
        vis[i][j] = 1;
        dfs(he,i+1,j,he[i][j],vis);
        dfs(he,i,j+1,he[i][j],vis);
        dfs(he,i-1,j,he[i][j],vis);
        dfs(he,i,j-1,he[i][j],vis);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& he) {
        int n  = he.size();
        int m  = he[0].size();
        vector<vector<int>>pac(n,vector<int>(m));
        vector<vector<int>>atl(n,vector<int>(m));
        for(int i = 0;i<n;i++){
            dfs(he,i,0,INT_MIN,pac);
            dfs(he,i,m-1,INT_MIN,atl);
        }
        for(int i = 0;i<m;i++){
            dfs(he,0,i,INT_MIN,pac);
            dfs(he,n-1,i,INT_MIN,atl);
        }
        vector<vector<int>>ans;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(pac[i][j]&&atl[i][j])ans.push_back({i,j});
            }
        }return ans;
    }
};