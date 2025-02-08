bool isleaf(Node *root)
{
    return (root != NULL && root->left == NULL && root->right == NULL);
}
void leftBoundary(Node *root, vector<int> &res)
{
    Node *c = root->left;
    while (c)
    {
        if (!isleaf(c))
            res.push_back(c->data);
        if (c->left)
            c = c->left;
        else
            c = c->right;
    }
}
void leaves(Node *root, vector<int> &res)
{
    if (isleaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        leaves(root->left, res);
    if (root->right)
        leaves(root->right, res);
}
void rightBoundary(Node *root, vector<int> &res)
{
    Node *c = root->right;
    vector<int> temp;
    while (c)
    {
        if (!isleaf(c))
            temp.push_back(c->data);
        if (c->right)
            c = c->right;
        else
            c = c->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}
vector<int> boundaryTraversal(Node *root)
{
    // code here
    vector<int> res;
    if (!root)
        return res;
    if (!isleaf(root))
        res.push_back(root->data);

    leftBoundary(root, res);
    leaves(root, res);
    rightBoundary(root, res);

    return res;
}