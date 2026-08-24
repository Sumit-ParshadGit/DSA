class Solution {
private:
    vector<long long> s;
    vector<long long> memo;
    int n;

    long long dfs(int i) {
        if (i >= n - 1) return s[n - 1];
        if (memo[i] != LLONG_MIN) return memo[i];
        return memo[i] = max(dfs(i + 1), s[i] - dfs(i + 1));
    }

public:
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        s.assign(n, 0);
        s[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            s[i] = s[i - 1] + stones[i];
        }

        memo.assign(n, LLONG_MIN);
        return (int)dfs(1);
    }
};