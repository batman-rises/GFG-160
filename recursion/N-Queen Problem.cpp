vector<vector<int>> nQueen(int n)
{
    // code here
    vector<bool> col(n, false);
    vector<bool> ndiag(2 * n - 1, false);
    vector<bool> rdiag(2 * n - 1, false);
    vector<vector<int>> res;
    vector<int> temp;
    solve(n, 0, col, ndiag, rdiag, res, temp);
    return res;
}

private:
void solve(int n, int c, vector<bool> &col, vector<bool> &ndiag, vector<bool> &rdiag, vector<vector<int>> &res, vector<int> &temp)
{
    if (c == n)
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !ndiag[c + i] && !rdiag[c - i + n - 1])
        {
            temp.push_back(i + 1);
            col[i] = true;
            ndiag[c + i] = true;
            rdiag[c - i + n - 1] = true;

            solve(n, c + 1, col, ndiag, rdiag, res, temp);

            temp.pop_back();
            col[i] = false;
            ndiag[c + i] = false;
            rdiag[c - i + n - 1] = false;
        }
    }
}