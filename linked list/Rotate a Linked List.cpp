Node *rotate(Node *head, int k)
{
    if (k == 0 || head == nullptr)
        return head;

    Node *c = head;
    int len = 1;

    while (c->next != NULL)
    {
        c = c->next;
        len += 1;
    }
    k %= len;
    if (k == 0)
        return head;

    c->next = head;
    c = head;
    for (int i = 1; i < k; i++)
        c = c->next;

    head = c->next;
    c->next = NULL;
    return head;
}