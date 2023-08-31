class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int brkpnt = -1;
    int n = nums.size();

   
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            brkpnt = i;
            break;
        }
    }

    
    if (brkpnt == -1) {
        reverse(nums.begin(), nums.end());
    }
    else {
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[brkpnt]) {
                swap(nums[i], nums[brkpnt]);
                break;
            }
        }
        reverse(nums.begin() + brkpnt + 1, nums.end());
    }
}

};