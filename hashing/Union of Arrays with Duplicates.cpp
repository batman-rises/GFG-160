int findUnion(vector<int> &a, vector<int> &b)
{
    set<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }
    for (int j = 0; j < b.size(); j++)
    {
        st.insert(b[j]);
    }
    return st.size();
}