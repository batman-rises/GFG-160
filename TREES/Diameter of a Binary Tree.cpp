int solve(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int lh = solve(root->left, maxi);
    int rh = solve(root->right, maxi);
    maxi = max(maxi, lh + rh);

    return 1 + max(lh, rh);
}
int diameter(Node *root)
{
    // Your code here
    int d = 0;
    solve(root, d);
    return d;
}