class Solution {
public:
    int ds(int n){
        int s = 0;
        while(n){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
        if(i==ds(nums[i]))return i;
        return -1;
    }
};