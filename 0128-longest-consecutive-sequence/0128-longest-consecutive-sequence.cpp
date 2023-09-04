class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int longCons = 0;
        for(int num : nums){
            if(!st.count(num-1)){
                int currnum = num;
                int currstreak = 1;;
                while(st.count(currnum+1)){
                    currnum += 1;
                    currstreak += 1;
                }
                longCons = max(longCons,currstreak);
            }
        }
        return longCons;
    }
};