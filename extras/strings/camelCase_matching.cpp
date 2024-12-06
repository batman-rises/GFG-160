vector<string> camelCase(vector<string> &arr, string &pat)
{
    vector<string> result;

    for (auto word : arr)
    {
        int i = 0;
        int j = 0;

        while (i < word.length() && j < pat.length())
        {
            // if i_th char of the word is lowercase then move to the next char
            if (islower(word[i]))
                i++;

            // if i_th char of the word is uppercase but doesn't match with the j_th char of the pattern,
            //  then move to the next word
            else if (word[i] != pat[j])
                break;

            // if matches and both are uppercases
            else
            {
                i++;
                j++;
            }
        }
        if (j == pat.length())
            result.push_back(word);
    }
    return result;
}