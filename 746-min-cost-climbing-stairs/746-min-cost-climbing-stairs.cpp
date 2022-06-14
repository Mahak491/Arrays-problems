class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = cost[1];
        int prev2 = cost[0];
        
        for(int i=2;i<cost.size();i++){
            int cur = cost[i]+ min(prev,prev2);
            prev2 = prev;
            prev = cur;
        }
        return min(prev,prev2);
    }
};