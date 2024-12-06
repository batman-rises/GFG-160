int str_to_int(string s)
{
    int i = 0;
    int res = 0;
    int sign = 1;
    int len = s.length();

    while (i < len && s[i] == ' ')
        i++;

    while (i < len && ((s[i] == '-') || s[i] == '+'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while (i < len && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        if (res > (INT_MAX - digit) / 10)
        {
            return (sign == -1) ? INT_MIN : INT_MAX;
        }

        res = res * 10 + digit;
        i++
    }
    return (sign * res);
}