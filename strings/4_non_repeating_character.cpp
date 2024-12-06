char NonRepeatingChar(string s)
{
    unordered_map<char, int> mpp;
    for (char ch : s)
    {
        mpp[ch]++;
    }
    for (char ch : s)
    {
        if (mpp[ch] == 1)
        {
            return ch;
        }
    }
    return '$';
}