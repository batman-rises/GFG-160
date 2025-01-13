int maxWater(vector<int> &arr)
{

    int i = 0, j = arr.size() - 1, ans = 0;
    while (i < j)
    {
        int c = min(arr[i], arr[j]) * (j - i);
        ans = max(ans, c);
        if (arr[i] < arr[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans;
}