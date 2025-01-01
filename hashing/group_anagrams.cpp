vector<vector<string>> anagrams(vector<string> &arr)
{
    int n = arr.size();
    unordered_map<string, vector<string>> mpp;
    for (int i = 0; i < n; i++)
    {
        string temp = arr[i];
        sort(temp.begin(), temp.end());
        mpp[temp].push_back(arr[i]);
    }
    vector<vector<string>> result;
    for (auto it : mpp)
    {
        result.push_back(it.second);
    }
    return result;
}