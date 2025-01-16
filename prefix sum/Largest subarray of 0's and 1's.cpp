int maxLen(vector<int> &arr)
{
    // Your code here
    unordered_map<int, int> mp;
    mp[0] = -1;
    int ans = 0, s = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        s += arr[i] == 1 ? 1 : -1;
        if (mp.find(s) != mp.end())
        {
            ans = max(ans, i - mp[s]);
        }
        else
        {
            mp[s] = i;
        }
    }
    return ans;
}