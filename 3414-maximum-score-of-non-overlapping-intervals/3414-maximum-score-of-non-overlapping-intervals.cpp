class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; ++i) intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end());
        vector<int> nxt(n, n);
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (intervals[m][0] > intervals[i][1]) r = m;
                else l = m + 1;
            }
            nxt[i] = l;
        }
        vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(5, {0, {}}));
        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {
                auto& skip = dp[i + 1][k];
                auto& nxtRes = dp[nxt[i]][k - 1];
                vector<int> takeSel = nxtRes.second;
                takeSel.push_back(intervals[i][3]);
                sort(takeSel.begin(), takeSel.end());
                pair<long long, vector<int>> take = {intervals[i][2] + nxtRes.first, takeSel};
                if (take.first > skip.first || (take.first == skip.first && take.second < skip.second))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }
        return dp[0][4].second;
    }
};