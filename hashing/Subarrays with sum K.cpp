int countSubarrays(vector<int> &arr, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        int rem = preSum - k;
        cnt += mpp[rem];
        mpp[preSum] += 1;
    }
    return cnt;
}