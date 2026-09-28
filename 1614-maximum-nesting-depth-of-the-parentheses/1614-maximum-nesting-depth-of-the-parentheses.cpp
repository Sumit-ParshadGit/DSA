class Solution {
public:
    int maxDepth(string s) {
        int t  = 0;
        int ans = 0;
        for(auto&ch:s){
            if(ch=='(')t++;
            if(ch==')')t--;
            ans = max(ans,t);
        }return ans;
    }
};