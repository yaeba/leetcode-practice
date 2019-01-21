int maxProfit(int* prices, int pricesSize) {
    
  // O(n) time, O(1) space
  // sell stocks before price goes down
  // buy and hold while price increases
  int maxProfit = 0;
    
  for (int i=0; i<pricesSize-1; i++) {
    if (prices[i+1] > prices[i]) {
      maxProfit += prices[i+1] - prices[i];
    }
  }
    
  return maxProfit;
}
