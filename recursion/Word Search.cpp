bool isWordExist(vector<vector<char>> &mat, string &word)
{
    // Code here
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == word[0])
            {
                vector<vector<bool>> visit(mat.size(), vector<bool>(mat[0].size(), false));
                if (check(mat, i, j, 0, word, visit))
                    return true;
            }
        }
    }
    return false;
}

private:
static bool check(vector<vector<char>> &mat, int i, int j, int ind, string &word, vector<vector<bool>> &v)
{
    if (ind == word.length())
    {
        return true;
    }
    if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || v[i][j] || mat[i][j] != word[ind])
    {
        return false;
    }
    v[i][j] = true;
    if (check(mat, i, j - 1, ind + 1, word, v) ||
        check(mat, i, j + 1, ind + 1, word, v) ||
        check(mat, i + 1, j, ind + 1, word, v) ||
        check(mat, i - 1, j, ind + 1, word, v))
    {
        return true;
    }
    v[i][j] = false;
    return false;
}