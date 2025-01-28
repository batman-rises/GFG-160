void permute(string &s, set<string> &ans, string cur, vector<bool> &vis)
{
    if (cur.size() == s.size())
    {
        ans.insert(cur);
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            permute(s, ans, cur + s[i], vis);
            vis[i] = false;
        }
    }
}
vector<string> findPermutation(string &s)
{
    // Code here there
    set<string> ans;
    vector<bool> vis(s.length(), false);

    permute(s, ans, "", vis);

    return vector<string>(ans.begin(), ans.end());
}