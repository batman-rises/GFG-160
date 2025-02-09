int func(Node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int left = max(0, func(root->left, maxi));
    int right = max(0, func(root->right, maxi));
    maxi = max(maxi, root->data + left + right);
    return (max(left, right) + root->data);
}
int findMaxSum(Node *root)
{
    // code here
    int maxi = INT_MIN;
    func(root, maxi);
    return maxi;
}