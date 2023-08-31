class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      unordered_map<int,int> mp;
      for(auto num:nums){
          if(mp.find(num) != mp.end()){
              return num;
          }
          mp[num]++;
      }
        return -1;
    }
};