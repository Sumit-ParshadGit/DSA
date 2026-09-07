class Solution {
public:
    int M = 1e9+7;
    int dp[2001];
    int sol(int n,vector<int>&pr){
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int t = (2*sol(n-1,pr)) % M;
        if(pr[n]!=0){
            int d = sol(pr[n]-1,pr)%M;
            t = (t-d+M)%M;
        }
        return dp[n] = t;
    }
    int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        vector<int>prev(n+1,0);
        vector<int>ls(26,0);
        for(int i = 1;i<=n;i++){
            int idx = s[i-1]-'a';
            prev[i] = ls[idx];
            ls[idx] = i;
        }
        return (sol(n,prev)-1+M)%M;
    }
};