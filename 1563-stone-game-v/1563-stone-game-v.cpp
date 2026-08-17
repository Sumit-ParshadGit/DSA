class Solution {
public:
    int dp[501][501];
    int sol(vector<int>&ps,int i,int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        for(int m = i;m<j;m++){
            int ls = ps[m]-(i-1>=0?ps[i-1]:0);
            int rs = ps[j]-ps[m];
            if(ls<rs){
                ans = max(ans,ls+sol(ps,i,m));
            }else if(ls>rs){
                ans = max(ans,rs+sol(ps,m+1,j));
            }else 
            ans = max({ans,ls+sol(ps,i,m),rs+sol(ps,m+1,j)});
        }return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& sv) {
        int n = sv.size();
        int s = 0;
        vector<int>ps;
        for(auto&el:sv){
            s+=el;
            ps.push_back(s);
        }
        memset(dp,-1,sizeof(dp));
        return sol(ps,0,n-1);
    }
};