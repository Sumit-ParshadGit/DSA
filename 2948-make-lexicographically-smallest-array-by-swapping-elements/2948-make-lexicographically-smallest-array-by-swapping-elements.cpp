class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int l) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> mp;

        unordered_map<int, vector<int>> grp;

        int gi = 0;
        grp[gi].push_back(sorted[0]);
        mp[sorted[0]] = gi;

        for (int i = 1; i < sorted.size(); i++) {
            if (sorted[i] - sorted[i - 1] > l) {
                gi++;
            }

            grp[gi].push_back(sorted[i]);
            mp[sorted[i]] = gi;
        }

        unordered_map<int, int> ptr;

        for (int i = 0; i < nums.size(); i++) {
            int group = mp[nums[i]];
            nums[i] = grp[group][ptr[group]++];
        }

        return nums;
    }
};