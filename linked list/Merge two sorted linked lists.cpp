Node *sortedMerge(Node *head1, Node *head2)
{
    // code here
    Node *n = NULL;
    Node *temp = NULL;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL && (head2 == NULL || head1->data < head2->data))
        {
            if (n == NULL)
            {
                n = head1;
                temp = head1;
            }
            else
            {
                temp->next = head1;
                temp = head1;
            }
            head1 = head1->next;
        }
        else
        {
            if (n == NULL)
            {
                n = head2;
                temp = head2;
            }
            else
            {
                temp->next = head2;
                temp = head2;
            }
            head2 = head2->next;
        }
    }
    if (temp != NULL)
    {
        temp->next = NULL;
    }
    return n;
}