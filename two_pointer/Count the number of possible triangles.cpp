int countTriangles(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int l = 0, e = i - 1;
        while (l < e)
        {
            if (arr[l] + arr[e] > arr[i])
            {
                ans += e - l;
                e--;
            }
            else
            {
                l++;
            }
        }
    }
    return ans;
}