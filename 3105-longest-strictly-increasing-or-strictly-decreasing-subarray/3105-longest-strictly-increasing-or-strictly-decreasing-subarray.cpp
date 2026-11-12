class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int prev = nums[0];
        int l = 1;
        int inc = 1;
        for(int i = 1;i<nums.size();i++){
            int cur = nums[i];
            if(inc){
                if(cur>prev){
                    l++;
                }else if(cur<prev){
                    l = 2;
                    inc = 0;
                }else l = 1;
            }else{
                if(cur<prev){
                    l++;
                }else if(cur>prev){
                    l = 2;
                    inc = 1;
                }else  l = 1;
            }
            prev = cur;
            ans = max(ans,l);
        }
        return ans;
    }
};