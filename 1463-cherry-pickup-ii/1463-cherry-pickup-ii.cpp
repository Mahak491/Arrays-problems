class Solution {
public:
    int f(int r,int c1,int c2,vector<vector<int>>& grid,int rows,int cols,vector<vector<vector<int>>>& dp){
    
		if(c1<0 || c2<0 || c1>=cols || c2>=cols) return -1e8;
		
		if(r==rows-1){
			if(c1==c2) return grid[r][c1];
			else return grid[r][c1] + grid[r][c2];
		}
		if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
    
		int maxx = -1e8;
		for(int d1=-1;d1<=1;d1++){
			for(int d2=-1;d2<=1;d2++){
				if (c1==c2) maxx = max(maxx,grid[r][c1]+f(r+1,c1+d1,c2+d2,grid,rows,cols,dp));
				
				else
                    maxx = max(maxx,grid[r][c1]+grid[r][c2]+f(r+1,c1+d1,c2+d2,grid,rows,cols,dp));
			}
		}
		return dp[r][c1][c2] = maxx;
	}
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m, -1)));
        return f(0,0,m-1,grid,n,m,dp);
    }
};