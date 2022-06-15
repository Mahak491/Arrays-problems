class Solution {
public:
    int f(int ind,int target,vector<int> &num,vector<vector<int>> &dp){
    if(ind==0){
        if(target % num[0] == 0){
            return (target/num[0]);
        }
        else
        {
            return 1e9;
        }
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    
    int notTake = 0+f(ind-1,target,num,dp);
    
    int take = INT_MAX;
    if(num[ind] <= target)
        take = 1+f(ind,target-num[ind],num,dp);
    
    return dp[ind][target] = min(take,notTake);
}
    
    int coinChange(vector<int>& num, int x) {
    int n = num.size();
    vector<vector<int>> dp(n,vector<int> (x+1,-1));
    int ans = f(n-1,x,num,dp);
    if(ans >= 1e9) return -1;
    return ans;   
    }
};