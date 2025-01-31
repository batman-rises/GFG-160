void solveSudoku(vector<vector<int>> &mat)
{
    // code here
    solve(mat, 0, 0);
}

private:
static bool solve(vector<vector<int>> &mat, int i, int j)
{
    if (i == 9)
    {
        return true;
    }
    int nI = (j == 8) ? i + 1 : i;
    int nJ = (j == 8) ? 0 : j + 1;

    if (mat[i][j] != 0)
    {
        return solve(mat, nI, nJ);
    }
    for (int val = 1; val <= 9; val++)
    {
        if (isValid(mat, i, j, val))
        {
            mat[i][j] = val;
            if (solve(mat, nI, nJ))
            {
                return true;
            }
            mat[i][j] = 0;
        }
    }
    return false;
}
static bool isValid(vector<vector<int>> &mat, int r, int c, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (mat[i][c] == val || mat[r][i] == val)
        {
            return false;
        }
    }
    int strR = (r / 3) * 3;
    int strC = (c / 3) * 3;
    for (int i = strR; i < strR + 3; i++)
    {
        for (int j = strC; j < strC + 3; j++)
        {
            if (mat[i][j] == val)
                return false;
        }
    }
    return true;
}