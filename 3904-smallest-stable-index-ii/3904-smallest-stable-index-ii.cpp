class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ma = INT_MIN;
        int n = nums.size();
        vector<int>mnm(nums);
        for(int i = n-2;i>=0;i--){
            int d = mnm[i];
            mnm[i] = min(d,mnm[i+1]);
        }
        for(int i = 0;i<nums.size();i++){
            ma = max(ma,nums[i]);
            int t = ma-mnm[i];
            if(t<=k)return i;
        }return -1;
    }
};