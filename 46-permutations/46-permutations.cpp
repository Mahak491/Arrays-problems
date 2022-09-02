class Solution {
public://tc - O(n!)*n  sc - O(n!)*n
    void recurpermutate(int index, vector<int>& nums,vector<vector<int>>&ans)
    {
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            recurpermutate(index+1,nums,ans);
            swap(nums[index],nums[i]);  
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>ans;
        recurpermutate(0,nums,ans);
        return ans;
    }
};