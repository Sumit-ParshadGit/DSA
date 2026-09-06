class Solution {
public:
    int dp[1001][1001];
    int sol(string &s, string &t,int i,int j){
        if(j>=t.size())return 1;
        if(i>=s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int c1 = 0;
        if(s[i]==t[j])c1 = sol(s,t,i+1,j+1);
        int c2 = sol(s,t,i+1,j);
        return dp[i][j] = c1+c2;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return sol(s,t,0,0);
    }
};