class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int s = 0;
        int ans= 0;
        for(int i = 0;i<k;i++){
            s+=cp[i];
        }
        ans = s;
        for(int i = 0;i<k;i++){
            s-=cp[k-1-i];
            s+=cp[n-1-i];
            ans = max(ans,s);
        }
        return ans;
    }
};