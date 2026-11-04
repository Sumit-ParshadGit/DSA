// class Solution {
// public:
//     typedef long long ll;
//     ll dp[100001][16];

//     ll sol(int ind,vector<int>& nums, int x, int k){
//         if(k==0)return 0;
//         if(ind>=nums.size()||(ind+x)>nums.size())return LLONG_MAX / 4;
//         if (1LL*k * x > (nums.size() - ind))
//             return LLONG_MAX / 4 ;
//         if(dp[ind][k]!=LLONG_MAX / 4)return dp[ind][k];
//         ll c1 = sol(ind+1,nums,x,k);
//         ll  a = 0;
//         int i = ind;
//         int j = ind+x;
//         vector<int>tmp;
//         while(i<j){
//             tmp.push_back(nums[i]);
//             i++;
//         }
//         sort(tmp.begin(),tmp.end());
//         ll med = tmp[tmp.size()/2];
//         for(int &x:tmp){
//             a += abs((ll)med-x);
//         }
//         ll next = sol(j, nums, x, k-1);
//         ll c2 = (next >= LLONG_MAX/4) ? LLONG_MAX/4 : a + next;
//         return dp[ind][k] = c1<c2?c1:c2;
//     }
//     ll minOperations(vector<int>& nums, int x, int k) {
//         for(auto&r:dp){
//             for(auto & c:r){
//                 c = LLONG_MAX / 4;
//             }
//         }
//         return sol(0,nums,x,k);
//     }
// };
class Solution {
public:
    using ll = long long;

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        if (1LL * x * k > n) return -1; 

        multiset<int> lo, hi;
        ll sumLo = 0, sumHi = 0;

        auto balance = [&]() {
            while (lo.size() > (x + 1) / 2) {
                int v = *lo.rbegin();
                lo.erase(prev(lo.end()));
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }

            while (lo.size() < (x + 1) / 2 && !hi.empty()) {
                int v = *hi.begin();
                hi.erase(hi.begin());
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }

            while (!hi.empty() && *lo.rbegin() > *hi.begin()) {
                int a = *lo.rbegin();
                int b = *hi.begin();

                lo.erase(prev(lo.end()));
                hi.erase(hi.begin());

                sumLo += b - a;
                sumHi += a - b;

                lo.insert(b);
                hi.insert(a);
            }
        };

        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }
            balance();
        };

        auto remove = [&](int v) {
            auto it = lo.find(v);

            if (it != lo.end()) {
                lo.erase(it);
                sumLo -= v;
            } else {
                it = hi.find(v);
                hi.erase(it);
                sumHi -= v;
            }

            balance();
        };

        vector<ll> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(nums[i]);

        for (int i = 0; i <= n - x; i++) {
            ll med = *lo.rbegin();

            cost[i] =
                med * (ll)lo.size() - sumLo +
                sumHi - med * (ll)hi.size();

            if (i < n - x) {
                remove(nums[i]);
                add(nums[i + x]);
            }
        }

        const ll INF = LLONG_MAX / 4;

        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, INF));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {

                dp[i][j] = dp[i + 1][j];

                if (i + x <= n && dp[i + x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        cost[i] + dp[i + x][j - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};