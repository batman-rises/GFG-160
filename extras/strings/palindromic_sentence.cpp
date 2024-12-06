bool sentencePalindrome(string &s)
{
    string x = "";
    for (char ch : s)
    {
        if (isalnum(ch))
        {
            x += tolower(ch);
        }
    }

    int l = 0;
    int r = x.length() - 1;

    while (l < r)
    {
        if (x[l] != x[r])
            return false;

        l++;
        r--;
    }
    return true;
}