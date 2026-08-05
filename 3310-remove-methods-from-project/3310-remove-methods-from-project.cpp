class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invo) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(int i = 0;i<invo.size();i++){
            adj[invo[i][0]].push_back(invo[i][1]);
            indeg[invo[i][1]]++;
        }
        vector<bool>vis(n,0);
        vector<bool>susp(n,0);

        queue<int>q;
        q.push(k);
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            susp[t] = 1;
            if(vis[t])continue;
            vis[t] = 1;
            for(auto&el:adj[t]){
                indeg[el]--;
                susp[el] = 1;
                q.push(el);
            }
        }
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(susp[i]&&indeg[i]>0){
                vector<int>ans;
                for(int j = 0;j<n;j++)
                ans.push_back(j);
                return ans;
            }
            if(!susp[i])ans.push_back(i);
        }
        return ans;
    }
};