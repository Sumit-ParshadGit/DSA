class Solution {
public:
    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long cnt = 0;

        for(int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            int bits = 0;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    bits++;

                    long long g = gcd(l, (long long)coins[i]);

                    if(l / g > x / coins[i]) {
                        l = x + 1;
                        break;
                    }

                    l = l / g * coins[i];
                }
            }

            if(bits % 2)
                cnt += x / l;
            else
                cnt -= x / l;
        }

        return cnt;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        vector<int> nc;

        for(int i = 0; i < coins.size(); i++) {
            int f = 1;

            for(int c : nc) {
                if(coins[i] % c == 0) {
                    f = 0;
                    break;
                }
            }

            if(f)
                nc.push_back(coins[i]);
        }

        long long l = 1;
        long long r = 1LL * nc[0] * k;

        while(l < r) {
            long long mid = l + (r - l) / 2;

            if(count(mid, nc) >= k)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};