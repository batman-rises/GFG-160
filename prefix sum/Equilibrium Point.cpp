int findEquilibrium(vector<int> &arr)
{
    int total = 0;
    for (i : arr)
    {
        total += i;
    }
    int c = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (c == total - c - arr[i])
            return i;

        c += arr[i];
    }
    return -1;
}