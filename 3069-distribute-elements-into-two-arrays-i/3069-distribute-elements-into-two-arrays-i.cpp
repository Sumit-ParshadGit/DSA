class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        if(nums.size()<=2)return nums;
        vector <int>v1;
        vector<int>v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            int a=v1.back();
            int b=v2.back();
            a>b?v1.push_back(nums[i]):v2.push_back(nums[i]);
            
        }
        v1.insert(v1.end(), v2.begin(), v2.end());
            return v1;
    }
};