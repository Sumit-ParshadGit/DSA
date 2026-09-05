class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int curs = 0;
        int ans = 0;
        mp[0] = 1;
        for(int &el:nums){
            curs+=el;
            ans+=mp[curs-k];
            mp[curs]++;
        }return ans;
    }
};