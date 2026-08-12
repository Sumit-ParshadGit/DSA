class Solution {
public:
    int maximum69Number (int nums) {
        vector<int>arr;
        while(nums){
            arr.push_back(nums%10);
            nums/=10;
        }
        int n = arr.size();
        int ans = 0;
        int f = 1;
        for(int i = n-1;i>=0;i--){
            int e = arr[i];
            if(f&&e==6){
                e = 9;
                f = 0;
            }
            ans= ans*10+e;
        }return ans;
    }
};