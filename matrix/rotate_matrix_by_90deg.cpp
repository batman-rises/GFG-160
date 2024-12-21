void rotateby90(vector<vector<int>> &mat)
{
    int n = mat.size();
    // transpose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // Reverse each column
    for (int j = 0; j < n; j++)
    {
        int top = 0, bottom = n - 1;
        while (top < bottom)
        {
            swap(mat[top][j], mat[bottom][j]);
            top++;
            bottom--;
        }
    }
}