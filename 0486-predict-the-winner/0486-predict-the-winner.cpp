class Solution {
public:
    int dp[21][21][3];
    int sol(vector<int>& nums,int l,int r,int f){
        if(l>r)return 0;
        if(dp[l][r][f]!=-1)return dp[l][r][f];
        if(f){
            return min(sol(nums,l+1,r,0),sol(nums,l,r-1,0));
        }
        int lft =0;
        lft= nums[l]+sol(nums,l+1,r,1);
        int rht =0;
        rht = nums[r]+sol(nums,l,r-1,1);
        return dp[l][r][f] = max(lft,rht);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        int ans = sol(nums,0,n-1,0);
        int sum=0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
        }
        return sum-ans<=ans;
    }
};