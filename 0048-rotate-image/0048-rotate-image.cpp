class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int n = matrix.size();   
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(auto&vec:matrix){
            reverse(vec.begin(),vec.end());
        }
    }
};