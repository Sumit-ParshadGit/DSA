class Solution {
public:
    typedef long long ll;
    #define M 1000000007
    ll dp[1001][1001];
    ll sol(int i,int n,int k){
        if(k==0)return 1;
        if(i>=n)return 0;
        if(dp[i][k] !=-1)return dp[i][k];
        ll skp = sol(i+1,n,k);
        ll tk = 0;
        for(int j = i+1;j<n;j++){
            tk +=sol(j,n,k-1);
        }
        return dp[i][k] = (skp+tk)%M;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return sol(0,n,k);
    }
};