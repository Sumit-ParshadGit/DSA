class Solution {
public:
    using ll = long long;
    int maxLength(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ll t = 1;
            ll p = 1;
            ll t2 = nums[i];
            for(int j = i;j<nums.size();j++){
                if(p*nums[j]>=INT_MAX)break;
                p =p*((ll)nums[j]);
                t = lcm(t,nums[j]);
                t2 = gcd(t2,nums[j]);
                if(p==(t*t2)) 
                ans = max(ans,j-i+1);
            }
        }return ans;
    }
};
