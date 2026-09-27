class Solution {
public:
    void sol(string &s,int i,int j){
        int a = i+1;
        int b = j-1;
        while(a<=b){
            swap(s[a],s[b]);
            a++;
            b--;
        }
        s.erase(j,1);
        s.erase(i,1);
    }
    string reverseParentheses(string s) {
        int f = 1;
        while(f){
            f = 0;
            int a = 0;
            int b = 0;
            for(int i = 0;i<s.size();i++){
                if(s[i]=='(')a = i;
                if(s[i]==')'){
                    b = i;
                    f  =1;
                    sol(s,a,b);
                    break;
                }
            }
        }
        return s;
    }
};