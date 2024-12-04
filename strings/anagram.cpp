// An anagram of a string is another string that contains the same characters,
// only the order of characters can be different. For example, act and tac are an anagram of each other.

bool areAnagrams(string &s1, string &s2)
{

    if (s1.length() != s2.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return (s1 == s2);
}