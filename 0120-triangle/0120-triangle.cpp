class Solution {
public:
    int dp[201][201];
    int sol(vector<vector<int>>& tr,int i,int j){
        if(i>=tr.size())return 0;
        if(j>=tr[i].size())return INT_MAX/2;
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int c1 = tr[i][j]+sol(tr,i+1,j);
        int c2 = tr[i][j]+sol(tr,i+1,j+1);
        return dp[i][j] = min(c1,c2);
    }
    int minimumTotal(vector<vector<int>>& tr) {
        for(auto&r:dp){
            for(int &x:r)
                x = INT_MAX;
        }
        return sol(tr,0,0);
    }
};