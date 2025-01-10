vector<int> countDistinct(vector<int> &arr, int k)
{

    vector<int> ans;
    unordered_map<int, int> mpp;
    k--;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
        if (i < k)
            continue;

        ans.push_back(mpp.size());

        if (mpp[arr[i - k]] == 1)
        {
            mpp.erase(arr[i - k]);
        }
        else
        {
            mpp[arr[i - k]]--;
        }
    }
    return ans;
}