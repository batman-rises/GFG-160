int countPairs(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    int ans = 0;
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum > target)
        {
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            int e1 = arr[left], e2 = arr[right], c1 = 0, c2 = 0;
            while (left <= right && arr[left] == e1)
            {
                left++;
                c1++;
            }
            while (left <= right && arr[right] == e2)
            {
                right--;
                c2++;
            }
            if (e1 == e2)
            {
                ans += (c1 * (c1 - 1)) / 2;
            }
            else
            {
                ans += c1 * c2;
            }
        }
    }
    return ans;
}