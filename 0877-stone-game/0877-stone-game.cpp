class Solution {
public:
    int dp[500][500][3];
    int sol(vector<int>& piles,int l,int r,int f){
        if(l>r)return 0;
        if(dp[l][r][f]!=-1)return dp[l][r][f];
        if(f){
            return min(sol(piles,l+1,r,0),sol(piles,l,r-1,0));
        }
        int lft = piles[l]+sol(piles,l+1,r,1);
        int rht = piles[r]+sol(piles,l,r-1,1);
        return dp[l][r][f] = max(lft,rht);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int ans = sol(piles,0,piles.size()-1,0);
        int s = 0;
        for(auto&el:piles){
            s+=el;
        }
        return s-ans<=ans;
    }
};