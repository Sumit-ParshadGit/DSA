class Solution {
public:
vector<int>vis;
    int dp[1001][1501][2];
    int sol(int i,int vis,vector<vector<int>>& items, int b){
        if(i>=items.size()||b<=0)return 0;
        if(dp[i][b][vis]!=-1)return dp[i][b][vis];
        int c1 =0;
        if(b>=items[i][1]){
        int t = 1;
        if(!vis)t = items[i][2];
        c1 =  t+max(sol(i,1,items,b-items[i][1]),sol(i+1,0,items,b-items[i][1]));
        }
        int c2 = sol(i+1,0,items,b);
        return dp[i][b][vis] = max(c1,c2);
    }

    int maximumSaleItems(vector<vector<int>>& items, int b) {
        memset(dp,-1,sizeof(dp));
        sort(items.begin(),items.end());
        int n = items.size();
        for(int i = 0;i<n;i++){
            int t = 0;
            for(int j = 0;j<n;j++){
                if(items[j][0]%items[i][0]==0)t++;
            }
            items[i].push_back(t);
        }
    vis.assign(1001,0);
        return sol(0,0,items,b);
    }
};