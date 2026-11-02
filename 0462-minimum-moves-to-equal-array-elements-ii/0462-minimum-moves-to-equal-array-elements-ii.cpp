class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int ind = nums.size()/2;
        int t  = nums[ind];
        for(int i =0;i<ind;i++){
            ans+=t-nums[i];
        }
        for(int i =ind+1;i<nums.size();i++){
            ans+=nums[i]-t;
        }
        return ans;
    }
};