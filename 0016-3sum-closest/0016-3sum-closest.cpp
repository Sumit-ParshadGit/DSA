class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int t) {
        int d = INT_MAX;
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sm = nums[i] + nums[j] + nums[k];
                int curr_dif = t>sm?t-sm:sm-t;
                if(curr_dif<d){
                    d = curr_dif ;
                    ans = sm;
                }
                if(sm>t){
                    k--;
                }else if(t>sm){
                    j++;
                }else return t;
                
            }
        }return ans;
    }
};