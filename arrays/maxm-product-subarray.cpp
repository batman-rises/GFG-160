int maxProduct(vector<int> &arr)
{
    int n = arr.size();
    int ans = INT_MIN;
    int pre = 1, suff = 1;

    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;

        pre *= arr[i];
        suff *= arr[n - i - 1];

        ans = max(ans, max(pre, suff));
    }

    return ans;
}