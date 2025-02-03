int height(Node *node)
{
    if (node == NULL)
        return -1;

    queue<Node *> q;
    q.push(node);
    int c = 0;
    while (!q.empty())
    {

        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *x = q.front();
            q.pop();
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
        c++;
    }
    return c - 1;
}