int hIndex(vector<int> &citations)
{
    // code here
    sort(citations.begin(), citations.end(), greater<int>());

    int n = citations.size();
    int h = 0;

    // Iterate through the sorted array to find the H-index
    for (int i = 0; i < n; i++)
    {
        if (citations[i] >= i + 1)
        {
            h = i + 1; // Update H-index
        }
        else
        {
            break; // Stop as soon as the condition fails
        }
    }

    return h;
}