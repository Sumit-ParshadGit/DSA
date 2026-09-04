class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mnm(nums);
        for(int i = n-2;i>=0;i--){
            mnm[i] = min(mnm[i],mnm[i+1]);
        }
        int ma = INT_MIN;
        for(int i = 0;i<n;i++){
            ma = max(ma,nums[i]);
            int d = ma-mnm[i];
            if(d<=k)return i;
        }return -1;
    }
};