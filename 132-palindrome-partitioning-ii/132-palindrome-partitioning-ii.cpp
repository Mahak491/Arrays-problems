class Solution {
public:
    //front partition
    int f(int ind,int n,string &str,vector<int> &dp){
        if(ind == n) return 0;
        int mincost = INT_MAX;
        if(dp[ind] != -1) return dp[ind];
        for(int j=ind;j<n;j++){
            if(ispalindrome(ind,j,str)){
                int cost = 1+f(j+1,n,str,dp);
                mincost = min(mincost,cost);
            }
        }
        return dp[ind] = mincost;
    }
    
    int minCut(string s) {
      int n = s.size();
      vector<int> dp(n,-1);
      return f(0,n,s,dp)-1;
    }
    
     bool ispalindrome(int start,int end,string &s)
     {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};