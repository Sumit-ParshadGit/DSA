class Solution {
public:
    int dp[500001][3];
    bool sol(int n,int f){
        if(n==0)return !f;
        bool res = 0;
        if(dp[n][f]!=-1)return dp[n][f];
        if(f){
            for(int  i = 1;i*i<=n;i++){
                int sqr =  i*i;
                res = res||sol(n-sqr,!f);
                if(res)return dp[n][f] =  1;
            }
        }else{
            res = 1;
            for(int  i = 1;i*i<=n;i++){
            int sqr =  i*i;
            res = res&&sol(n-sqr,!f);
            if(!res)return dp[n][f]  = 0;
        }
        }
        return dp[n][f] =  res;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return sol(n,1);
    }
};