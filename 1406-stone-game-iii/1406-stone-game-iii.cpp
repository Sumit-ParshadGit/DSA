// class Solution {
// public:
//     vector<int>dp;
//     int sol(vector<int>&sv,int i,int n){
//         if(i>=n)return 0;
//         if(dp[i]!=-1)return dp[i];
//         int on = sv[i]-sol(sv,i+1,n);
//         int tw = INT_MIN;
//         if(i+1<n)tw = sv[i]+sv[i+1]-sol(sv,i+2,n);
//         on = max(on,tw);
//         int thr = INT_MIN;
//         if(i+2<n)thr = sv[i]+sv[i+1]+sv[i+2]-sol(sv,i+3,n);
//         on = max(on,thr);
//         return on;
//     }
//     string stoneGameIII(vector<int>& stoneValue) {
//         int n = stoneValue.size();
//         dp.resize(n+1,-1);
//         int al = sol(stoneValue,0,n);
//         return al>0?"Alice":al<0?"Bob":"Tie";
//     }
// };
class Solution {
public:
    vector<int>dp;
    int sol(vector<int>& sv,int i,int n){
        if(i>=n)return 0;
        if(dp[i]!=INT_MIN)return dp[i];

        int res = INT_MIN;
        int on = sv[i]-sol(sv,i+1,n);
        res = max(res,on);
        int tw =INT_MIN;
        if(i+1<n)tw= sv[i]+ sv[i+1]-sol(sv,i+2,n);
        res = max(res,tw);
        int thr =INT_MIN;
        if(i+2<n) thr=sv[i]+sv[i+1]+ sv[i+2]-sol(sv,i+3,n);
        res = max(res,thr);
        return dp[i]= res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n+1,INT_MIN);
        string s1 = "Alice";
        string s2 = "Bob";
        string s3 = "Tie";
 
        int al = sol(stoneValue,0,n);
        return al>0?s1:al==0?s3:s2;
    }
};