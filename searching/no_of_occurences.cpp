int countFreq(vector<int> &arr, int target)
{
    int n = arr.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            c++;
    }
    return c;
}