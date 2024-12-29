vector<int> intersectionWithDuplicates(vector<int> &a, vector<int> &b)
{
    set<int> st(a.begin(), a.end());
    set<int> intersection;
    for (int num : b)
    {
        if (st.count(num))
        {
            intersection.insert(num);
        }
    }
    return vector<int>(intersection.begin(), intersection.end());
}