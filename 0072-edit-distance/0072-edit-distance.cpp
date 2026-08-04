class Solution {
public:
    int dp[501][501];
    int sol(const string &w1,const string &w2,int i,int j,int n1,int n2){
        if(j>=n2)return n1-i;
        if(i>=n1)return n2-j;
        if(dp[i][j]!=-1)return dp[i][j];
        if(w1[i]==w2[j])return dp[i][j] =  sol(w1,w2,i+1,j+1,n1,n2);
        return dp[i][j] = 1+ min(
            {sol(w1,w2,i+1,j,n1,n2),
            sol(w1,w2,i+1,j+1,n1,n2),
            sol(w1,w2,i,j+1,n1,n2)}
        );
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        memset(dp,-1,sizeof(dp));
        return sol(word1,word2,0,0,n1,n2);
    }
};