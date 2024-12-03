// MOORE'S VOTING ALGO
//  ONLY 2 ELEMENTS CAN HAVE N/3 REPS IN AN ARRAY
vector<int> findMajority(vector<int> &arr)
{
    // Your code goes here.
    int n = arr.size();
    int c1 = 0, c2 = 0;
    int el1 = -1;
    int el2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (c1 == 0 && el2 != arr[i])
        {
            c1 = 1;
            el1 = arr[i];
        }
        if (c2 == 0 && el1 != arr[i])
        {
            c2 = 1;
            el2 = arr[i];
        }
        else if (el1 == arr[i])
            c1++;
        else if (el2 == arr[i])
            c2++;

        else
        {
            c1--;
            c2--;
        }
    }
    vector<int> ans;
    c1 = 0;
    c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el1 == arr[i])
            c1++;
        if (el2 == arr[i])
            c2++;
    }
    int minm = (int)(n / 3) + 1; // MAJORITY MARK
    if (c1 >= minm)
        ans.push_back(el1);
    if (c2 >= minm)
        ans.push_back(el2);
    sort(ans.begin(), ans.end());
    return ans;
}