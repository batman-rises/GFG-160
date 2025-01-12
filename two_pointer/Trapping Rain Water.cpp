int maxWater(vector<int> &arr)
{
    // code here
    int n = arr.size();
    if (n == 0)
        return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int wt = 0;

    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= leftMax)
            {
                leftMax = arr[left];
            }
            else
            {
                wt += leftMax - arr[left];
            }
            left++;
        }
        else
        {
            if (arr[right] >= rightMax)
            {
                rightMax = arr[right];
            }
            else
            {
                wt += rightMax - arr[right];
            }
            right--;
        }
    }
    return wt;
}