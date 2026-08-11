class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ma = nums[0];
        for(auto&el:nums)
        ma = max(ma+2,el);
        int i = 0;
        vector<bool>is_present(ma,0);
        for(auto&el:nums)
        is_present[el] =1;
        int s = nums[0];
        while(i+1<nums.size()&&nums[i+1]==(nums[i]+1)){
        s+=nums[i+1];
        i++;}
        if(s>ma)return s;
        for(int i = s;i<=ma+1;i++)
        if(!is_present[i])return i;
        return -1;
    }
};