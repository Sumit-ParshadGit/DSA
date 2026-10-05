class Solution {
public:
    int bsl(int l,int r,vector<int>&num,int t){
        int ans = -1;
        while(l<=r){
        int mid = l+(r-l)/2;
        if(num[mid]==t){
            ans = mid;
            r = mid-1;
        }
        else if(num[mid]>=t)r = mid-1;
        else l = mid+1;}
        return ans;
        }
    int bsr(int l,int r,vector<int>&num,int t){
        int ans = -1;
        while(l<=r){
        int mid = l+(r-l)/2;
        if(num[mid]==t){
            ans = mid;
            l = mid+1;
        }
        else if(num[mid]>=t)r = mid-1;
        else l = mid+1;}
        return ans;
        }
    vector<int> searchRange(vector<int>& nums, int target) {
        int r = nums.size()-1;
        return {bsl(0,r,nums,target),bsr(0,r,nums,target)};
    }
};