int getMinDiff(vector<int> &arr, int k)
{
    // code here
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int diff = arr[n - 1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;
    int minm = 0, maxm = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        minm = min(smallest, arr[i + 1] - k);
        maxm = max(largest, arr[i] + k);

        if (minm < 0)
            continue;

        diff = min(diff, maxm - minm);
    }
    return diff;
}