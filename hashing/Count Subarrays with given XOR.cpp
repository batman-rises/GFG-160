long subarrayXor(vector<int> &arr, int k)
{
    long ans = 0;

    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int curXor = 0;

    for (int i : arr)
    {
        curXor ^= i;

        if (mpp.find(curXor ^ k) != mpp.end())
        {
            ans += mpp[curXor ^ k];
        }

        mpp[curXor]++;
    }
    return ans;
}