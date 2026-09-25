class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oc = 0;
        int i =0;
        int ans = 0;
        for(int j = 0;j<nums.size();j++){
            if(nums[j]%2==1)oc++;
            if(oc==k){
                int t1 = 0;
                int t2 = 1;
                while(oc==k){
                    t1++;
                    if(nums[i]%2==1){
                        oc--;
                    }
                    i++;
                }
                int j2 = j+1;
                while(j2<nums.size()&&nums[j2]%2!=1){
                    t2++;
                    j2++;
                }
                ans+=t1*t2;
                ans = max(ans,t1);
            }
        }return ans;
    }
}; 