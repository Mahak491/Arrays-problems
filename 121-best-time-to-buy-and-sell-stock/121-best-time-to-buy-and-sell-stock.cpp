class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int mini = prices[0];
      int profit = 0;
      for(int i=1;i<prices.size();i++){
          int cost = prices[i] - mini;
          profit = max(profit,cost);
          mini = min(mini,prices[i]); //remembering the past thats why dp!! keep track of min will help to find the profit
      }
        return profit;
    }
};