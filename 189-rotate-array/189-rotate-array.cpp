class Solution {
public:
    void reverse(vector<int> &num,int low,int high){
        while(low<high){
            swap(num[low],num[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        // brute force
     int n = nums.size();
    /* if ((n == 0) || (k <= 0))
      {
            return;
      }
            
     // Make a copy of nums
      vector<int> numsCopy(n);
      for (int i = 0; i < n; i++)
      {
         numsCopy[i] = nums[i];
      }
            
      // Rotate the elements.
      for (int i = 0; i < n; i++)
      {
         nums[(i + k)%n] = numsCopy[i];
      } 
       */ 
        
        
        //optimal
        k = k % n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
    }
};