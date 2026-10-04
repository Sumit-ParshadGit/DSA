class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int f = 1;
        for(char ch:s){
            if(ch==')')f = 0;
        }
        if(f)return 0;
        for(int i = 0;i<s.size();i++){
            int t = 0;
            int c = 0;
            int st = i;
            for(int j = i;j<s.size();j++){
                if(s[j]=='(')c++;
                else c--;
                if(c<0){c = 0;st = j+1;continue;}
                if(c==0){
                    t = max(j-st+1,t);
                    
                }
            }
            ans = max(ans,t);
        }return ans;
    }
};