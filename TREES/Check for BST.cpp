bool check(Node *root, long minm, long maxm)
{
    if (!root)
        return true;

    if (root->data <= minm || root->data >= maxm)
        return false;

    return check(root->left, minm, root->data) && check(root->right, root->data, maxm);
}
bool isBST(Node *root)
{
    // Your code here
    return check(root, LONG_MIN, LONG_MAX);
}