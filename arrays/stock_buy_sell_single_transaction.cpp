int maximumProfit(vector<int> &prices)
{
    // code here
    int n = prices.size();
    int maxProfit = 0;
    int minm = prices[0];
    for (int i = 0; i < n; i++)
    {
        int cost = prices[i] - minm;
        maxProfit = max(maxProfit, cost);
        minm = min(minm, prices[i]);
    }
    return maxProfit;
}