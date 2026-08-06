class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConn) {
        int n = isConn.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < isConn[i].size(); j++) {
                if (i != j && isConn[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n, 0);

        queue<int> q;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                q.push(i);
                while (!q.empty()) {
                    int f = q.front();
                    q.pop();
                    if (vis[f]) continue;
                    vis[f] = 1;
                    for (auto& el : adj[f]) {
                        q.push(el);
                    }
                }
            }
        }

        return ans;
    }
};