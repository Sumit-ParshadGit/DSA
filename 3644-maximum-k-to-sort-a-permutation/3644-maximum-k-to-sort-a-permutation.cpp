class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MAX;
        int f = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=(i)){
                ans&=nums[i];
                f = 0;}
        }
        if(f)return 0;
        return ans;
    }
};