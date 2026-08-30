class Solution {
public:
    int dp[366][366];
    int sol(vector<int>& days, vector<int>& costs,int i,int paid_upto){
        if(i>=days.size())return 0;
        if(dp[i][paid_upto]!=-1)return dp[i][paid_upto];
        if(days[i]>paid_upto){
            int case1 = costs[0]+sol(days,costs,i+1,days[i]);
            int case2 = costs[1]+sol(days,costs,i+1,min(days[i]+6,365));
            int case3 = costs[2]+sol(days,costs,i+1,min(days[i]+29,365));
            return dp[i][paid_upto]= min({case1,case2,case3});
        }
        return dp[i][paid_upto]= sol(days,costs,i+1,paid_upto);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return sol(days,costs,0,0);
    }
};