class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        unordered_set<int> zerrow, zerocol;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j] == 0){
                    zerrow.insert(i);
                    zerocol.insert(j);
                }
            }
        }
        
        for(int x:zerrow){
            for(int j=0;j<cols;j++){
                matrix[x][j] = 0;
            }
        }
        
        for(int y:zerocol){
            for(int i=0;i<rows;i++){
                matrix[i][y] = 0;
            }
        }
    }
};