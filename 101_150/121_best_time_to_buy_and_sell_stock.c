int maxProfit(int* prices, int pricesSize) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    
    for (int i=0; i<pricesSize; i++) {
        minPrice = prices[i] < minPrice ? prices[i] : minPrice;
        int profit = prices[i] - minPrice;
        maxProfit = profit > maxProfit ? profit : maxProfit;
    }
    
    return maxProfit;
}
