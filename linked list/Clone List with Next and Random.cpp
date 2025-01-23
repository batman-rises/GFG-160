Node *cloneLinkedList(Node *head)
{
    // Write your code here
    if (!head)
        return NULL;

    Node *c = head;
    while (c)
    {
        Node *t = new Node(c->data);
        t->next = c->next;
        c->next = t;
        c = t->next;
    }

    c = head;
    while (c)
    {
        if (c->random)
        {
            c->next->random = c->random->next;
        }
        c = c->next->next;
    }
    c = head;
    Node *chead = head->next;
    Node *cc = chead;
    while (c)
    {
        c->next = c->next->next;
        if (cc->next)
        {
            cc->next = cc->next->next;
        }
        c = c->next;
        cc = cc->next;
    }
    return chead;
}