class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ma = 0;
        int mi = 0;
        int cma = 0;
        int cmi = 0;
        for(int x:nums){
            cma = max(x,x+cma);
            cmi = min(x,x+cmi);
            ma = max(cma,ma);
            mi = min(cmi,mi);
        }
        return max(ma,-mi);
    }
};
