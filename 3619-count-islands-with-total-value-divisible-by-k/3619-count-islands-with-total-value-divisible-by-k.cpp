class Solution {
public:
    bool vis[1001][1001] = {0};
    bool bfs(vector<vector<int>>& grid, int k,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j] = 1;
        long long t = 0;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            t+= grid[r][c];
            q.pop();
            if(r+1<grid.size()&&grid[r+1][c]!=0&&!vis[r+1][c]){
                q.push({r+1,c});
                vis[r+1][c] = 1;
            }
            if(r-1>=0&&grid[r-1][c]!=0&&!vis[r-1][c]){
                q.push({r-1,c});
                vis[r-1][c] = 1;
            }
            if(c+1<grid[0].size()&&grid[r][c+1]!=0&&!vis[r][c+1]){
                q.push({r,c+1});
                vis[r][c+1] = 1;
            }
            if(c-1>=0&&grid[r][c-1]!=0&&!vis[r][c-1]){
                q.push({r,c-1});
                vis[r][c-1] = 1;
            }
        }
        return t%k==0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]!=0&&!vis[i][j]&&bfs(grid,k,i,j))ans++;
            }
        }
        return ans;
    }
};