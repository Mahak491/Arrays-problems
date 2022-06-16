// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
// int f(int N,int W,int val[],int wt[],vector<vector<int>> dp){
//     if(N == 0){
//         return ((W/wt[0])*val[0]);
//     }
    
//     if(dp[N][W] != -1) return dp[N][W];
    
//     int notTake = 0 + f(N-1,W,val,wt,dp);
    
//     int take = INT_MIN;
//     if(wt[N] <= W)
//     take = val[N] + f(N,W-wt[N],val,wt,dp);
    
//     return dp[N][W] = max(take,notTake);
    
// }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int> (W+1,0));
        // return f(N-1,W,val,wt,dp);
        for(int i=wt[0];i<=W;i++){
            dp[0][i] = ((int)i/wt[0])*val[0];
        }
        
        for(int ind = 1;ind <N;ind++){
            for(int cap = 0;cap <= W;cap++){
                int notTake = 0 + dp[ind-1][cap];
                
                int take = INT_MIN;
                if(wt[ind] <= cap){
                    take = val[ind] + dp[ind][cap-wt[ind]];
                }
                dp[ind][cap] = max(take,notTake);
            }
        }
        return dp[N-1][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends