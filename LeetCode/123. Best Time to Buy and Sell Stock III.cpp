/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

class Solution {
  public:
  int maxProfit(vector<int>& prices) {
        
    if (prices.size() <= 1) return 0;

    int leftMin = prices[0];
    int rightMax = prices[prices.size() - 1];

    vector<int> leftProfits(prices.size(), 0);
    vector<int> rightProfits(prices.size() + 1, 0);

    for (int l = 1; l < prices.size(); ++l) {
        
        //left to right:  profits  Algorithm: current price - MINimum so far
        leftProfits[l] = max(leftProfits[l - 1], prices[l] - leftMin);
        leftMin = min(leftMin, prices[l]);

        //right to left: profits  Algorithm: MAXimum so far - current price
        int r = prices.size() - 1 - l;
        rightProfits[r] = max(rightProfits[r + 1], rightMax - prices[r]);
        rightMax = max(rightMax, prices[r]);
    }

    //maximum of left +  right  
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); ++i) {
      maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
    }
    return maxProfit;
  }
};
