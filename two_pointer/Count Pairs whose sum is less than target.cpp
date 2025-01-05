int countPairs(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int c = 0, st = 0, end = arr.size() - 1;
    while (st < end)
    {
        if (arr[st] + arr[end] < target)
        {
            c += end - st;
            st++;
        }
        else
        {
            end--;
        }
    }
    return c;
}