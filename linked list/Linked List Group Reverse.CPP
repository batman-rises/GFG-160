Node *reverseKGroup(Node *head, int k)
{
    // code here
    int len = getL(head);
    Node *origH = NULL;
    Node *origT = NULL;
    Node *tempH = NULL;
    Node *tempT = NULL;
    Node *cur = head;

    while (len > 0)
    {
        int j = k;
        j = min(j, len);
        while (j > 0)
        {
            Node *nex = cur->next;
            if (tempH == NULL)
            {
                tempH = cur;
                tempT = cur;
            }
            else
            {
                cur->next = tempH;
                tempH = cur;
            }
            cur = nex;
            j--;
            len--;
        }
        if (origH == NULL)
        {
            origH = tempH;
            origT = tempT;
        }
        else
        {
            origT->next = tempH;
            origT = tempT;
        }
        tempH = NULL;
        tempT = NULL;
    }
    if (origT != nullptr)
    {
        origT->next = NULL;
    }
    return origH;
}
int getL(Node *head)
{
    int l = 0;
    while (head != NULL)
    {
        l++;
        head = head->next;
    }
    return l;
}