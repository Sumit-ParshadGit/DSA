// class Solution {
// public:
// int n,m;
//     bool dfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>>&vis,set<pair<int,int>>&st){
//         if(i>=n||j>=m||i<0||j<0)return 0;
//         if(vis[i][j]||board[i][j]=='X')return 1;
//         if(board[i][j]=='O'){
//             vis[i][j] = 1;
//             st.insert({i,j});
//         }
//         return 
//         dfs(board,i+1,j,vis,st)&&
//         dfs(board,i,j+1,vis,st)&&
//         dfs(board,i-1,j,vis,st)&&
//         dfs(board,i,j+1,vis,st);
//     }
//     void solve(vector<vector<char>>& board) {
//          n = board.size();
//          m = board[0].size();
//          vector<vector<bool>>vis(n,vector<bool>(m,0));
//          for(int i = 0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 if(!vis[i][j]&&board[i][j]=='O'){
//                     set<pair<int,int>>st;
//                     if(dfs(board,i,j,vis,st)){
//                         for(auto&el:st){
//                             int i1 = el.first;
//                             int j1 = el.second;
//                             board[i1][j1] = 'X';
//                         }
//                     }
//                 }
//             }
//          }
//     }
// };

class Solution {
public:
int n,m;
    bool dfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>>&vis,set<pair<int,int>>&st){
        if(i>=n||j>=m||i<0||j<0)return 0;
        if(vis[i][j]||!vis[i][j]&&board[i][j]=='X')return 1;
        if(board[i][j]=='O'){
            st.insert({i,j});
            vis[i][j] = 1;
            }
        
        return dfs(board,i+1,j,vis,st)&
        dfs(board,i-1,j,vis,st)&
        dfs(board,i,j+1,vis,st)&
        dfs(board,i,j-1,vis,st);
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j]&&board[i][j]=='O'){
                    set<pair<int,int>>st;
                   if(dfs(board,i,j,vis,st)){
                    for(auto&el:st){
                        int i1 = el.first;
                        int j1 = el.second;
                        board[i1][j1] = 'X';
                    }
                   }
                }
            }
        }
    }
};