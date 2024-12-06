vector<int> LSP(string s)
{
    int n = s.size();
    int i = 1;
    int prevLps = 0;
    vector<int> lps(n, 0);

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
    return lps;
}

bool KMP(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = LSP(pattern);
    int i = 0, j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
            return true;

        if (i < n && text[i] != pattern[j])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
    return false;
}

int minRepeats(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    int minReps = (m + n - 1) / n;
    string text = s1;

    for (int i = 1; i < minReps; i++)
    {
        text += s1;
    }

    if (KMP(text, s2))
        return minReps;

    text += s1;
    if (KMP(text, s2))
        return minReps + 1;

    return -1;
}