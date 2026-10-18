class Solution {
public:
    static int d(int n){
        int ans=  0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        vector<int>sorted(nums);
        auto lambda = [&](int n1,int n2){
            int d1 = d(n1);
            int d2 = d(n2);
            if(d1!=d2){
                return d1<d2;
            }
            return n1<n2;
        };
        sort(sorted.begin(),sorted.end(),lambda);
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        int sc = 0;
        for(int i = 0;i<nums.size();i++){
            int cur = nums[i];
            int exp = sorted[i];
            if(cur==exp)continue;
            int idx = mp[exp];
            nums[i] = exp;
            nums[idx] = cur;
            mp[exp] = i;
            mp[cur] = idx;
            sc++;
        }
            return sc;
    }
};