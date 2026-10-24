class Solution {
public:
    int dp[101][101];

    int sol(vector<vector<int>>& mat,int i,int j){
        if(i>=mat.size())return 0;
        if(j<0||(j>=mat[0].size()))return INT_MAX/2;
        if(dp[i][j]!=INT_MAX/2)return dp[i][j];
        int c1 = mat[i][j]+sol(mat,i+1,j-1);
        int c2 = mat[i][j]+sol(mat,i+1,j+1);
        int c3 = mat[i][j]+sol(mat,i+1,j);
        return dp[i][j] = min({c1,c2,c3});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
       for(auto&r:dp){
        for(int& col:r){
            col = INT_MAX/2;
        }
       }
       int ans = INT_MAX;
        for(int j = 0;j<mat[0].size();j++){
            ans = min(ans,sol(mat,0,j));
        };
        return ans;
    }
};