class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto&el:nums)mp[el]++;
        for(int i=1;;i++){
            int t=k*i;
            if(mp[t]==0)return t;
        }return 1;
        
    }
};