Node *reverseList(struct Node *head)
{

    if (head == NULL)
        return NULL;
    Node *prev = NULL;
    Node *cur = head;
    Node *temp = cur->next;

    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}