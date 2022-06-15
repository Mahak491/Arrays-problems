class Solution {
public:
    int f(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(target == 0) return true;
        
        if(ind == 0) return nums[0] == target;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool notTake = f(ind-1,target,nums,dp);
        bool take = false;
        
        if(nums[ind] <= target){
            take = f(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=notTake || take;
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        
        if(totalSum % 2 == 1) return false;
        else{
             int k = totalSum/2;
             vector<vector<int>> dp(n,vector<int> (k+1,-1));
             return f(n-1,k,nums,dp);
        }   
    }
};