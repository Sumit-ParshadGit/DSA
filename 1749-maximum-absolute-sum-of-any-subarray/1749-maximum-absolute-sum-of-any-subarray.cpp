// class Solution {
// public:
//     int maxAbsoluteSum(vector<int>& nums) {
//         int ma = 0;
//         int mi = 0;
//         int cma = 0;
//         int cmi = 0;
//         for(int x:nums){
//             cma = max(x,x+cma);
//             cmi = min(x,x+cmi);
//             ma = max(cma,ma);
//             mi = min(cmi,mi);
//         }
//         return max(ma,-mi);
//     }
// };
// class Solution {
// public:
//     int maxAbsoluteSum(vector<int>& nums) {
//         int s1 = INT_MIN;
//         int s2 = INT_MIN;
//         int s= 0;
//         for(int i = 0;i<nums.size();i++){
//             s+=nums[i];
//             s1 = max(s1,s);
//             if(s<0)s = 0;
//             nums[i] = -nums[i];
//         }
//         for(int i = 0;i<nums.size();i++){
//             s+=nums[i];
//             s2 = max(s2,s);
//             if(s<0)s = 0;
//         }return max(s1,s2);
//     }
// };

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int s1 = INT_MIN;
        int s2 = INT_MIN;
        int s11= 0;
        int s12= 0;
        for(int i = 0;i<nums.size();i++){
            s11+=nums[i];
            s12+=-nums[i];
            s1 = max(s1,s11);
            s2 = max(s2,s12);
            if(s11<0)s11 = 0;
            if(s12<0)s12 = 0;
        }
        return max(s1,s2);
    }
};