class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<bool>vis(rooms.size(),0);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto&el:rooms[f])
            if(!vis[el]){
                vis[el] = 1;
                q.push(el);
            }
        }
        for(auto el:vis)
        if(!el)return 0;
        return 1;
    }
};