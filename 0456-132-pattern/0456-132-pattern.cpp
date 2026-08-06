class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>>st;
        int mi = nums[0];
        for(int i = 1;i<nums.size();i++){
            while(st.size()&&st.top().first<=nums[i])st.pop();
            if(st.size()&&st.top().second<nums[i])return true;
            st.push({nums[i],mi});
            mi = min(mi,nums[i]);
        }return 0;
    }
};