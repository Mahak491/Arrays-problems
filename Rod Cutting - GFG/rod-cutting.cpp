// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int f(int price[],int ind,int N,vector<vector<int>> &dp){
      
      if(ind == 0){
          return N*price[0];
      }
      
      if(dp[ind][N] != -1) return dp[ind][N];
      
      int notTake = 0 + f(price,ind-1,N,dp);
      int take = INT_MIN;
      
      int rodlen = ind+1;
      
      if(rodlen <= N) take = price[ind] + f(price,ind,N-rodlen,dp);
      
      return dp[ind][N] = max(take,notTake);
      
  }
  
    int cutRod(int price[], int n) {
        //code here
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(price,n-1,n,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends