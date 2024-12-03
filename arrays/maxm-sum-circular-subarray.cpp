/*  BRUTE

    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n;  // Handle cases where k >= n
        if (k == 0) return;

    // Step 1: Reverse the entire array
        reverse(arr.begin(), arr.end());

    // Step 2: Reverse the first k elements
        reverse(arr.begin(), arr.begin() + k);

    // Step 3: Reverse the remaining elements
        reverse(arr.begin() + k, arr.end());
    }
    int kadane(vector<int> &arr) {
        // code here...
        int n=arr.size();
        int sum=0;
        int maxm=INT_MIN;
        for(int i=0;i<n;i++){

            sum+=arr[i];

            if(sum > maxm)
            maxm=sum;

            if(sum<0)
            sum=0;
        }
        return maxm;
    }
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int n=arr.size();
        int res=0;
        for(int i=0;i<n;i++){
            rotate(arr,i);
            int sum=kadane(arr);
            res=max(res,sum);
        }
        return res;
    }
 */

int kadaneMin(vector<int> &nums, int n)
{
    int sum = 0;
    int minm = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        minm = min(sum, minm);

        if (sum > 0)
            sum = 0;
    }
    return minm;
}
int kadaneMax(vector<int> &nums, int n)
{
    int sum = 0;
    int maxm = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        maxm = max(sum, maxm);

        if (sum < 0)
            sum = 0;
    }
    return maxm;
}
int circularSubarraySum(vector<int> &nums)
{

    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int minSum = kadaneMin(nums, n);
    int maxSum = kadaneMax(nums, n);
    int cir_Sum = sum - minSum;
    if (maxSum > 0)
        return max(cir_Sum, maxSum);

    return maxSum;
}