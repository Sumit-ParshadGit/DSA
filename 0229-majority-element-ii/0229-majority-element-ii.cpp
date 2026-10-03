class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        int f = nums.size()/3;
        for(int x:nums){
            if(mp[x]>f)continue;
            mp[x]++;
            if(mp[x]>f)ans.push_back(x);
        }
        return ans;
    }
};