class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int m1 = -1;
        int m2 = -1;
        for(int i = 0;i<n;i++){
            if(m1<=nums[i]){
                m2 = m1;
                m1 = nums[i];
            }
            else if(m2<nums[i])m2 = nums[i];
        }return (m1-1)*(m2-1);
    }
};