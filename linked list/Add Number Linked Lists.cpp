private:
Node *reverseList(Node *head)
{
    Node *temp = NULL;
    while (head)
    {
        Node *x = head->next;
        if (temp == NULL)
        {
            temp = head;
            temp->next = NULL;
        }
        else
        {
            head->next = temp;
            temp = head;
        }
        head = x;
    }
    return temp;
}

public:
Node *addTwoLists(Node *num1, Node *num2)
{
    // code here
    Node *l1 = reverseList(num1);
    Node *l2 = reverseList(num2);
    Node *cur = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry > 0)
    {
        int v1 = (l1 != NULL) ? l1->data : 0;
        int v2 = (l2 != NULL) ? l2->data : 0;
        int sum = v1 + v2 + carry;
        carry = sum / 10;
        Node *temp = new Node(sum % 10);
        temp->next = cur;
        cur = temp;

        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }
    while (cur != NULL && cur->data == 0)
        cur = cur->next;

    return cur;
}