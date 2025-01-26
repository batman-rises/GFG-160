void removeLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            Node *prev = NULL;
            slow = head;
            if (slow == fast)
            {
                while (fast->next != slow)
                {
                    fast = fast->next;
                }
                fast->next = NULL;
                return;
            }
            while (slow != fast)
            {
                prev = fast;
                fast = fast->next;
                slow = slow->next;
            }

            prev->next = NULL;
            return;
        }
    }
}