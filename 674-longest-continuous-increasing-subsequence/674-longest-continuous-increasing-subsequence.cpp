class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int length = 1;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] < nums[i+1]){
                length++;
            }else{
                length = 1;
            }
             ans = max(ans,length);
        }
        return ans;
    }
};

