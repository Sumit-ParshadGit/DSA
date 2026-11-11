class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k>s.size())return 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            unordered_map<char,int>mp;
            for(int j = i;j<s.size();j++){
                mp[s[j]]++;
                int f = 1;
                for(auto&x:mp){
                    if(x.second<k){
                        f = 0;
                        break;
                    }
                }
                if(f){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};