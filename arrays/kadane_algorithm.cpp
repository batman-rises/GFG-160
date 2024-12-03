int maxSubarraySum(vector<int> &arr)
{
    // code here...
    int n = arr.size();
    int sum = 0;
    int maxm = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > maxm)
            maxm = sum;

        if (sum < 0)
            sum = 0;
    }
    return maxm;
}