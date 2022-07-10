class Solution {
public:
    int f(int ind,int buy,int cap,vector<vector<vector<int>>> &dp,vector<int> &prices,int n){
        if(ind == n || cap == 0)
            return 0;
        
        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        
        if(buy == 1){
            return dp[ind][buy][cap] = max(-prices[ind]+f(ind+1,0,cap,dp,prices,n),0+f(ind+1,1,cap,dp,prices,n));
        }
        
            else
            return dp[ind][buy][cap] = max(prices[ind]+f(ind+1,1,cap-1,dp,prices,n),0+f(ind+1,0,cap,dp,prices,n));

    
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,dp,prices,n); 
    }
};