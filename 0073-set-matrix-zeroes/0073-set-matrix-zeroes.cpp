class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<int>row;
        vector<int>col;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int r:row){
            for(int j = 0;j<n;j++){
                mat[r][j] = 0;
            }
        }
        for(int c:col){
            for(int i = 0;i<m;i++){
                mat[i][c] = 0;
            }
        }
    }
};