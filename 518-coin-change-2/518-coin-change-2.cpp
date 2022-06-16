class Solution {
public:
     int f(int ind,int target,vector<int> &num,vector<vector<long>> &dp){
    if(ind==0){
            return (target%num[0]==0);
    }
         
    if(dp[ind][target] != -1) return dp[ind][target];
    
    long notTake = f(ind-1,target,num,dp);
    
    long take = 0;
    if(num[ind] <= target)
        take = f(ind,target-num[ind],num,dp);
    
    return dp[ind][target] = take+notTake;
}
    
    int change(int x, vector<int>& num) {
    int n = num.size();
    vector<vector<long>> dp(n,vector<long> (x+1,-1));
    return f(n-1,x,num,dp);
    }
};