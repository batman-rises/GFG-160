bool twoSum(vector<int> &arr, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
            return true;
        mpp[num] = i;
    }
    return false;
}