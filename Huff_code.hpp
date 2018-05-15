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

void printCode(Node *root, std::string str, int &j)
    {
        if (root == nullptr)
            return;

        if (root->data == '$')
        {
            printCode(root->left, str + "0", j);
            printCode(root->right, str + "1", j);
        j++;
        }

        if (root->data != '$')
        {
            std::cout << root->data << " : " << str << std::endl;
            printCode(root->left, str + "0", j);
            printCode(root->right, str + "1", j);
        }
    }
