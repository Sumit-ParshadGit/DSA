class Solution {
public:
    int dp[100001];
    int sol(int i,int t,vector<int>& nums){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int tk = 0;
        if((t^nums[i])!=0||i<nums.size()-1)tk = 1+sol(i+1,t^nums[i],nums);
        int skp = sol(i+1,t,nums);
        return dp[i] = max(tk,skp);
    }   
    int longestSubsequence(vector<int>& nums) {
        int f = 1;
        for(auto&el:nums){
            if(el!=0){
                f = 0;break;
            }
        }if(f)return 0;
        memset(dp,-1,sizeof(dp));
        return sol(0,0,nums);
    }
};