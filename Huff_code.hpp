class Huffmancodes
{
    struct Node
    {
        char data;
        int freq;
        Node *left;
        Node *right;
        Node(char data, int freq)
        {
            left = right = nullptr;
            this->data = data;
            this->freq = freq;
        }
    };

    struct compare
    {
        bool operator()(Node *l, Node *r)
        {
            return (l->freq > r->freq);
        }
    };
};