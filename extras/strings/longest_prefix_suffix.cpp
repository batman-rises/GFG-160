int longestPrefixSuffix(string &s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    int i = 1;
    int prevLps = 0;
    while (i < n)
    {
        if (s[i] == s[prevLps])
        {
            prevLps++;
            lps[i] = prevLps;
            i++;
        }
        else
        {
            if (prevLps != 0)
            {
                prevLps = lps[prevLps - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps[n - 1];
}