int func(vector<int> &arr, int maxm_pgs)
{
    int cnt = 1;
    int pagesStudent = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesStudent + arr[i] <= maxm_pgs)
        {
            pagesStudent += arr[i];
        }
        else
        {
            cnt++;
            pagesStudent = arr[i];
        }
    }
    return cnt;
}
int findPages(vector<int> &arr, int k)
{
    if (k > arr.size())
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int no_of_students;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        no_of_students = func(arr, mid);

        if (no_of_students > k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}