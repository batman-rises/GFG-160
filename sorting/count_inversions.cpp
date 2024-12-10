int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0; // To count inversions

    // Merge process with inversion counting
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
            cnt += (mid - left + 1); // Count inversions
        }
    }

    // Add remaining elements from left and right subarrays
    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    // Copy sorted temp array back into original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;
    int cnt = 0;

    cnt += mergeSort(arr, low, mid);      // Count inversions in the left half
    cnt += mergeSort(arr, mid + 1, high); // Count inversions in the right half
    cnt += merge(arr, low, mid, high);    // Count cross-inversions

    return cnt;
}

int inversionCount(vector<int> &arr)
{
    if (arr.empty())
        return 0; // Handle empty array case
    return mergeSort(arr, 0, arr.size() - 1);
}