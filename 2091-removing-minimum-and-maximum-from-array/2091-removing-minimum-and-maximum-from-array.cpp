class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i = 0;
        int j = 0;
        for(int k = 0;k<nums.size();k++){
            if(nums[k]<nums[i]){
                i = k;
            }
            if(nums[k]>nums[j])j = k;
        }
        int n = nums.size();
        if(i>j)swap(i,j);
        return min({i+1+n-j,j+1,n-i});
    }
};