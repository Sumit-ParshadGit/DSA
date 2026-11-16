class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size()>k){
            string ans = "";
            int t = 0;
            for(int i = 0;i<s.size();i++){
                t+= s[i]-'0';
                if((i+1)%k==0){
                ans+=to_string(t);
                t = 0;
                }
            }
            if(s.size()%k!=0){
                ans+=to_string(t);
                t = 0;
                }
            s  = ans;
        }
        return s;
    }
};