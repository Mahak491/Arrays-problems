class Solution {
public:
    int f(int ind,int buy,int n,vector<int> &prices,vector<vector<int>> &dp,int fee){
       if(ind == n)
           return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy == 1)
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,n,prices,dp,fee),0+f(ind+1,1,n,prices,dp,fee));
        else
            return dp[ind][buy] = max(prices[ind] + f(ind+1,1,n,prices,dp,fee)- fee,0 + f(ind+1,0,n,prices,dp,fee));
     }    
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,n,prices,dp,fee);
    }
};