Node *LCA(Node *root, Node *n1, Node *n2)
{
    // code here
    if (root == NULL)
        return NULL;
    int cur = root->data;
    if (cur < (n1->data) && cur < (n2->data))
        return LCA(root->right, n1, n2);
    if (cur > (n1->data) && cur > (n2->data))
        return LCA(root->left, n1, n2);
    return root;
}