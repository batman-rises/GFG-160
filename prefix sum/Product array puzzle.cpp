vector<int> productExceptSelf(vector<int> &arr)
{
    // code here
    int n = arr.size();
    vector<int> res(n);
    int p = 1, zero = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
        }
        else
        {
            p *= arr[i];
        }
    }

    if (zero > 1)
    {
        return vector<int>(n, 0);
    }
    if (zero == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                res[i] = p;
            }
            else
            {
                res[i] = 0;
            }
        }
        return res;
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = p / arr[i];
    }
    return res;
}