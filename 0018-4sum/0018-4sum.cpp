class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.empty())
            return ans;
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long tar2 = static_cast<long long>(target) - nums[i] - nums[j];
                int front = j+1;
                int back = n-1;
                while(front < back){
                    int two_sum = nums[front] + nums[back];
                    if(two_sum < tar2) front++;
                    else if(two_sum > tar2) back--;
                    else{
                        vector<int>quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        ans.push_back(quad);
                        
                        while(front<back and nums[front]==quad[2]) ++front;
                        while(front<back and nums[back]==quad[3]) --back;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1] ) j++;
            }
            while(i+1<n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};