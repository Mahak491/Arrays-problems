class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      //   vector<int> temp;
        int n = nums.size();
      // for(int i=0;i<n;i++){
      //     for(int j=i+1;j<n;j++){
      //         if(nums[i]+nums[j] == target){
      //             temp.push_back(i);
      //             temp.push_back(j);
      //         }
      //     }
      // } 
      //   return temp;
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int val = target - nums[i];
            if(mp.find(val) != mp.end()){
               ans.push_back(mp[val]);
               ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};