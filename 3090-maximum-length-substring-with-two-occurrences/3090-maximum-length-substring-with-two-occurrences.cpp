class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int>mp;
        int n=s.length();
        while(j<n){
            mp[s[j]]++;
            while(i<j&&mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);j++;
        }return ans;
    }
};