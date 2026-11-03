class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ma=0;
        for(int x:nums){
            ma=max(x,ma);
        }
        int ans=0;
        for(int x:nums)
        ans+=ma-x;
        return ans;
    }
};