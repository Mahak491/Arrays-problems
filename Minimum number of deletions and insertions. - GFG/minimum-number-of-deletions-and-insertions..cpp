// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	int f(string s1,string s2){
	    int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i] = 0;
        }

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1]) //ind-1 means ind
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else
                    dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }

        return dp[n][m];
    }

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	   // int ans =  f(str1,str2);
	    return str1.size() + str2.size() - 2*f(str1,str2);
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends