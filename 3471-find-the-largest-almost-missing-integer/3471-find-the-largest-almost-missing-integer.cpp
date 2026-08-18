class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i = 0;i<=nums.size()-k;i++){
            set<int>st;
            for(int j = i;j<i+k;j++){
                st.insert(nums[j]);
            }
            for(int e:st)mp[e]++;
        }

        int ans  = -1;
        for(auto&el:mp){
            if(el.second==1){
                ans = max(ans,el.first);
            }
        }return ans;
    }
};