int findMin(vector<int> &arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[mid])
        { // left sorted
            ans = min(arr[low], ans);
            low = mid + 1;
        }
        else
        { // right sorted
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}