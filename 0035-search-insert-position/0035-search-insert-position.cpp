class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int i= 0;
        int j = nums.size()-1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(nums[m]==t)return m;
            if(nums[m]<t){
                i = m+1;
            }else j = m-1;
        }return i;
    }
};