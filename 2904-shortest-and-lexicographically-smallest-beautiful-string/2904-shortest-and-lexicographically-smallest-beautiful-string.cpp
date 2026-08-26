class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        string ans;
        int l = s.length()+1;
        int ones = 0;
        for(int j = 0;j<s.length();j++){
            if(s[j]=='1')ones++;
            while(ones>k){
                if(s[i]=='1')ones--;
                i++;
            }
            if(ones==k){
                while(s[i]=='0')i++;
                if(l>j-i+1||(l==(j-i+1)&&ans>s.substr(i,j-i+1))){
                    l = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
            }
        }return ans;
    }
};