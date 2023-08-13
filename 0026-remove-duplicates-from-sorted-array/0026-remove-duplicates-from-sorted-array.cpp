class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       set<int> st;
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        vector<int> result;
        for (auto x : st) {
            result.push_back(x);
        }
        
        for (int i = 0; i < result.size(); i++) {
            nums[i] = result[i];
        }

        return st.size();  
    }
};