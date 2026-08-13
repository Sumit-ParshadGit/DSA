class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int,int>mp;
        int i = 0;
        int j = 0;
        int n = f.size();
        int ans  = 0;
        while(j<n){
            mp[f[j]]++;
            while(i<j&&mp.size()>2){
                mp[f[i]]--;
                if(mp[f[i]]==0){
                    mp.erase(f[i]);
                }i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }return ans;
    }
};