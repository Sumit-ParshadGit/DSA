class Solution {
public:
    int dp[100001];
    int sol(vector<int>& costs,int i){
        if(i==costs.size()-1)return 0;
        if(i>=costs.size())return INT_MIN/2;
        if(dp[i]!=INT_MAX)return dp[i];
        int ans = INT_MAX;
        for(int j = 1;j<=3;j++){
            if(i+j>=costs.size())break;
            ans = min(
                ans,
                costs[i+j]+(j)*(j)+sol(costs,i+j)
            );
        }return dp[i]= ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        costs.push_back(0);
        for(int i = n;i>0;i--){
            costs[i] = costs[i-1];
        }costs[0] = 0;
        for(int&x:dp)x = INT_MAX;
        return sol(costs,0);
    }
};