class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        int i = 0;
        int j = n-1;
        while(i<j){
            int m = i+(j-i)/2;
            if(m%2==1)m--;
            if(nums[m]==nums[m+1])
            i=min(m+2,n-1);
            else j = m;
        }
        return nums[i];
    }
};