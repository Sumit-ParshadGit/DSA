class Solution {
public:
    int MOD=  1000000007;
    int dp[501][501][2];
    int sol(vector<vector<int>>& grid,int i,int j,int lr){
        if(i==grid.size()-1&&j==grid[0].size()-1){
            return 1;
        }
        if(i>=grid.size()||j>=grid[0].size())return 0;
        if(dp[i][j][lr]!=-1){
            return (dp[i][j][lr])%MOD ;
        }
        if(grid[i][j]==1){
            int c1 = 0;
            if(lr==0){
                c1 = sol(grid,i+1,j,1)%MOD;
            }else{
                c1 = sol(grid,i,j+1,0)%MOD;
            }
            dp[i][j][lr] = c1%MOD;
        }else{
            int c2 = 0;
            int c3 = 0;
            c2 = sol(grid,i+1,j,1)%MOD;;
            c3 = sol(grid,i,j+1,0)%MOD;
            dp[i][j][lr] = (c2+c3)%MOD;
        }
        return dp[i][j][lr];
    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        ans = sol(grid,0,0,0)%MOD;;
        return ans;
    }
};