class Solution {
public:
    int dp[2001][2001];
    bool is_palin(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }return 1;
    }
    int sol(string &s,int i,int j,int k){
        if(i>=s.length()||j>=s.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int t = 0;
        int res = INT_MIN;
        if(is_palin(s,i,j)){
            t = 1 +sol(s,j+1,j+k,k);
            res = max(t,res);
            int grow = sol(s,i,j+1,k);
            res = max(grow,res);
            int skp = sol(s,i+1,j+1,k);
            res = max(skp,res);
            return dp[i][j] = res;
        }
        res = max(t,res);
        int grow = sol(s,i,j+1,k);
        res = max(grow,res);
        int skp = sol(s,i+1,j+1,k);
        res = max(skp,res);
        return dp[i][j] = res;
    }
    int maxPalindromes(string s, int k) {
        if(k==1)return s.length();
        
        memset(dp,-1,sizeof(dp));
        return sol(s,0,k-1,k);
    }
};