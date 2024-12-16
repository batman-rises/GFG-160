int kthElement(vector<int> &a, vector<int> &b, int k)
{
    // code here
    int n = a.size(), m = b.size();

    // Ensure the first array is smaller for binary search optimization
    if (n > m)
        return kthElement(b, a, k);

    int low = max(0, k - m), high = min(k, n); // Binary search bounds

    while (low <= high)
    {
        int cut1 = (low + high) / 2; // Partition point in array 'a'
        int cut2 = k - cut1;         // Remaining elements in array 'b'

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1]; // Left of partition in 'a'
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1]; // Left of partition in 'b'
        int r1 = (cut1 == n) ? INT_MAX : a[cut1];     // Right of partition in 'a'
        int r2 = (cut2 == m) ? INT_MAX : b[cut2];     // Right of partition in 'b'

        // Check if partitions are valid
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2); // K-th element found
        }
        else if (l1 > r2)
        {
            high = cut1 - 1; // Move left in 'a'
        }
        else
        {
            low = cut1 + 1; // Move right in 'a'
        }
    }

    return -1; // Invalid case
}