class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int t) {
        vector<int>ans;
        int sc = 0;
        int tc = 0;
        for(int x:nums){
            if(x<t)sc++;
            if(x==t)tc++;
        }
        for(int i = sc;i<sc+tc;i++){
            ans.push_back(i);
        }
        return ans;
    }
};