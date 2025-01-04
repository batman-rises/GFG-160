int countTriplets(vector<int> &arr, int target)
{
    int n = arr.size();
    if (n < 3)
        return 0;
    int cnt = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int curSum = arr[i] + arr[left] + arr[right];
            if (curSum == target)
            {
                cnt++;

                while (left < right && arr[left] == arr[left + 1])
                {
                    left++;
                }
                while (left < right && arr[right] == arr[right - 1])
                {
                    right--;
                }

                left++;
                right--;
            }
            else if (curSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return cnt;
}