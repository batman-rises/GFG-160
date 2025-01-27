struct Node
{
    int key, value;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};
class LRUCache
{
private:
    int cap;
    unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;
    void addN(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void removeN(Node *node)
    {
        Node *prevN = node->prev;
        Node *nextN = node->next;
        prevN->next = nextN;
        nextN->prev = prevN;
    }
    void m2f(Node *node)
    {
        removeN(node);
        addN(node);
    }
    void removeLRU()
    {
        Node *lru = tail->prev;
        removeN(lru);
        cache.erase(lru->key);
        delete lru;
    }

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int capa)
    {
        // code here
        cap = capa;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache()
    {
        Node *cur = head;
        while (cur)
        {
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
    }

    // Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            m2f(node);
            return node->value;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value)
    {
        // your code here
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->value = value;
            m2f(node);
        }
        else
        {
            if (cache.size() == cap)
            {
                removeLRU();
            }
            Node *newN = new Node(key, value);
            addN(newN);
            cache[key] = newN;
        }
    }
};