// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         map<int,int>mp;
//         int ma = 0;
//         int mi = INT_MAX;
//         for(auto&el:nums){
//             mp[el]=1;   
//             ma = max(ma,el);
//             mi = min(mi,el);
//         }
//         vector<int>ans;
//         for(int i = mi;i<ma;i++){
//             if(!mp[i])ans.push_back(i);
//         }return ans;
//     }
// };
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i = 0;i<nums.size()-1;i++){
            for(int j = nums[i]+1;j<nums[i+1];j++){
                ans.push_back(j);
            }
        }return ans;
    }
};
