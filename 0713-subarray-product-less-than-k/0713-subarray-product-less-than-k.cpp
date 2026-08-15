class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int p = 1;
        int ans = 0;
        while(i<=j&&j<n){
            p*=nums[j];
            while(i<=j&&p>=k){
                p/= nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }return ans;
    }
};