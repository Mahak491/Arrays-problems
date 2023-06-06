class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        int mid = (l+r)/2;
        while(l<r){
            if(nums[mid] < nums[mid+1]){
                l = mid+1;
            }else {
                r = mid;
            }
            mid = (l+r)/2;
        }
        return l;
    }
};