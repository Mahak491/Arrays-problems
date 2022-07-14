class Solution {
public:
    int f(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if(i > j) return 0;
    
    int maxi = INT_MIN;
    
    if(dp[i][j] != -1) return dp[i][j];
    for(int k=i;k<=j;k++){
        int steps = arr[i-1]*arr[k]*arr[j+1] + f(i,k-1,arr,dp)+f(k+1,j,arr,dp);
        
       maxi = max(maxi,steps); 
    }
    
    return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& arr) {
        int N = arr.size();
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return f(1,N,arr,dp);
    }
};