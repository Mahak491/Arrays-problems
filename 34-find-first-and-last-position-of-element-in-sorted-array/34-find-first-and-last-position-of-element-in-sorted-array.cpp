class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return {-1,-1};
        else 
               return {findfirstIndex(nums,target),findlastIndex(nums,target)};
    }
    
    int findfirstIndex(vector<int>nums,int target){
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                high=mid-1;
                continue;
            }
            if(nums[mid] < target){
                low=mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
    
    int findlastIndex(vector<int>nums,int target){
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                low=mid+1;
                continue;
            }
            if(nums[mid] < target){
                low=mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};