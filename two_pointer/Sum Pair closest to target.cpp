vector<int> sumClosest(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<int> ans;
    int st = 0, end = arr.size() - 1;
    int cur = INT_MAX;
    while (st < end)
    {
        int sum = arr[st] + arr[end];
        if (abs(sum - target) < cur)
        {
            cur = abs(target - sum);
            ans = {arr[st], arr[end]};
        }
        if (sum < target)
        {
            st++;
        }
        else if (sum > target)
        {
            end--;
        }
        else
        {
            return ans;
        }
    }
    return ans;
}