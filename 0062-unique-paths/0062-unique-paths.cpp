class Solution {
public:
    
    int getuniquePaths(vector<vector<int>>& dp,int m,int n){
        if(m == 0 && n == 0)
            return 1;
        if(m < 0 || n < 0)
            return 0;
        if(dp[m][n] != -1) return dp[m][n];
            
        int up = getuniquePaths(dp,m-1,n);
        int left = getuniquePaths(dp,m,n-1);
        
        return dp[m][n] = up+left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return getuniquePaths(dp,m-1,n-1);
        
    }
};