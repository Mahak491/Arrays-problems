class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int rsize = matrix.size();
       int csize = matrix[0].size();
       unordered_set<int> r,c;
       for(int i=0;i<rsize;i++){
           for(int j=0;j<csize;j++){
               if(matrix[i][j] == 0){
                   r.insert(i);
                   c.insert(j);
               }
           }
       }
        for(auto x:r){
            for(int j=0;j<csize;j++){
                matrix[x][j] = 0;
            }
        }
        
        for(auto y:c){
            for(int i=0;i<rsize;i++){
                matrix[i][y] = 0;
            }
        }
    }
};