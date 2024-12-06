string addBinary(string &s1, string &s2)
{
    int n = s1.length();
    int m = s2.length();
    string res = "";
    int carry = 0;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int len = max(n, m);

    for (int i = 0; i < len; i++)
    {
        int digitA = (i < n) ? s1[i] - '0' : 0;
        int digitB = (i < m) ? s2[i] - '0' : 0;

        int total = digitA + digitB + carry;
        char ch = (total % 2) + '0';
        res = ch + res;
        carry = total / 2; // 0+1=1 && 1%2=1 an wkt it shouldn't have a carry thats wht 1/2=0
    }

    if (carry)
        res = "1" + res;

    return res;
}