bool canWePlace(vector<int> &stalls, int dist, int k)
{
    int cnt = 1;
    int lastCoordinate = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastCoordinate >= dist)
        {
            cnt++;
            lastCoordinate = stalls[i];
        }
    }
    if (cnt >= k)
        return true;
    else
        return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{

    // Write your code here
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}