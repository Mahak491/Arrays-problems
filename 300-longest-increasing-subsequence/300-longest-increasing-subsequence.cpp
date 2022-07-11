class Solution {
public:
   /* int f(int ind,int prev_ind,vector<int> &nums, vector<vector<int>> &dp,int n){
        if(ind == n) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        
        
        int len = 0 + f(ind+1,prev_ind,nums,dp,n);
        
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len,1+f(ind+1,ind,nums,dp,n));
        }
        return dp[ind][prev_ind+1] = len;
    }*/
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return f(0,-1,nums,dp,n);
        
        //tabulation
        
        /*vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int ind = n-1; ind >= 0; ind--){
            for(int prev = ind-1; prev >= -1; prev--){
                int len = 0 + dp[ind+1][prev+1];
        
                if(prev == -1 || nums[ind] > nums[prev]){
                    len = max(len,1+dp[ind+1][ind+1]);
                }
             dp[ind][prev+1] = len;
            }
        }
         return dp[0][-1+1];*/
        
        // vector<int> dp(n,1);
        // int maxi = 1;
        // for(int i=0;i<n;i++){
        //     for(int prev=0;prev<=i-1;prev++){
        //         if(nums[prev] < nums[i]){
        //             dp[i] = max(dp[i],1+dp[prev]);
        //         }
        //     }
        //     maxi = max(maxi,dp[i]);
        // }
        // return maxi;
        
        vector<int> temp;
        temp.push_back(nums[0]);
        int l = 1;
        for(int i=1;i<n;i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                l++;
            }else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind] = nums[i];
            }
        }
        // return temp.size();
        return l;
    }
};