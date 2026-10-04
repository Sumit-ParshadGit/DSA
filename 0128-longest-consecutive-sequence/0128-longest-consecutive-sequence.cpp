class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans = 0;
        for(int x:st){
            int t = x;
            int tmp = 0;
            if(!st.count(t-1)){
                while(st.count(t)){
                    tmp++;
                    t++;
                }
                ans = max(ans,tmp);
            }
        }return ans;
    }
};