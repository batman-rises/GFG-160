int maximumProfit(vector<int> &price)
{
    // code here
    int n = price.size();
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        // Add profit for every upward trend
        if (price[i] > price[i - 1])
        {
            profit += price[i] - price[i - 1];
        }
    }
    return profit;
}

/**
 * The code calculates the maximum profit from multiple stock transactions by adding the profit from every upward trend in stock prices.

Logic: It checks each consecutive pair of days:
If the price on day i is higher than on day i-1, the difference is added to the profit (simulating buying on day i-1 and selling on day i).
Key Insight: Only upward price trends contribute to profit, while downward trends are ignored.
Result: The sum of these profitable differences gives the total maximum profit for the given prices.
Example:
For price = {7, 1, 5, 3, 6, 4}:

Profit between days 2 & 3 (1 -> 5) = 
5
−
1
=
4
5−1=4
Profit between days 4 & 5 (3 -> 6) = 
6
−
3
=
3
6−3=3
Total Profit = 4 + 3 = 7.
 */