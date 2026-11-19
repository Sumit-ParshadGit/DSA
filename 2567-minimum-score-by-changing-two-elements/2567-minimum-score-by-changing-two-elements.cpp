class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n==3)return 0;
        sort(nums.begin(),nums.end());

        int c1 = nums[n-3]-nums[0];
        int c2 = nums[n-2]-nums[1];
        int c3 = nums[n-1]-nums[2];
        int ans = min({
            c1,c2,c3
        });
        return ans;
    }
};