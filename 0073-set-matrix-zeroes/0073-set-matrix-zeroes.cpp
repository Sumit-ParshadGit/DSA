// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& mat) {
//         vector<int>row;
//         vector<int>col;
//         int m = mat.size();
//         int n = mat[0].size();
//         for(int i = 0;i<m;i++){
//             for(int j = 0;j<n;j++){
//                 if(mat[i][j]==0){
//                     row.push_back(i);
//                     col.push_back(j);
//                 }
//             }
//         }
//         for(int r:row){
//             for(int j = 0;j<n;j++){
//                 mat[r][j] = 0;
//             }
//         }
//         for(int c:col){
//             for(int i = 0;i<m;i++){
//                 mat[i][c] = 0;
//             }
//         }
//     }
// };
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
       bool rz = 0;
       bool cz = 0;
       int m = mat.size();
       int n = mat[0].size();
       for(int i = 0;i<m;i++){
        if(mat[i][0]==0){
            cz = 1;
            break;
        }
       }
       for(int j = 0;j<n;j++){
        if(mat[0][j]==0){
            rz = 1;
            break;
        }
       }
       for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            if(mat[i][j]==0){
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
       }
       for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            if(mat[i][0]==0||mat[0][j]==0){
                mat[i][j] = 0;
            }
        }
       }
       if(cz)
        for(int i = 0;i<m;i++){
            mat[i][0]=0;
        }
       if(rz)
        for(int j = 0;j<n;j++){
            mat[0][j]=0;
        }
    }
};