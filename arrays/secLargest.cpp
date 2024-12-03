int getSecondLargest(vector<int> &arr)
{
    // Code Here
    int n = arr.size();
    int largest = INT_MIN;
    int secLar = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secLar = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > secLar)
        {
            secLar = arr[i];
        }
    }
    return (secLar == INT_MIN) ? -1 : secLar;
}