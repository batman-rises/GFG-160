int longestSubarray(vector<int> &arr, int k)
{
    // code here
    unordered_map<int, int> pre;
    int c = 0, l = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        c += arr[i];

        if (c == k)
            l = i + 1;

        if (pre.find(c - k) != pre.end())
        {
            l = max(l, i - pre[c - k]);
        }
        if (pre.find(c) == pre.end())
        {
            pre[c] = i;
        }
    }
    return l;
}