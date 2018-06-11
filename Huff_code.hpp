#include <iostream>
#include <queue>
#include <string>
#include <map>

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




void printCode(Node *root, std::string str)
{
    if (root == nullptr)
        return;

    if (root->data == '$')
    {
        printCode(root->left, str + "0");
        printCode(root->right, str + "1");
    }

    if (root->data != '$')
    {
        std::cout << root->data << " : " << str << std::endl;
        printCode(root->left, str + "0");
        printCode(root->right, str + "1");
    }
}





<<<<<<< HEAD
Node* HuffmanCodes(std::map<char, int> &frequency)
=======
Node *HuffmanCodes(char data[], int freq[], int size)
>>>>>>> 78f67c15ea69e4971520aab185570aa16755f102
{
    struct Node *left, *right, *top;

    std::priority_queue<Node *, std::vector<Node *>, compare> minHeap;

    for (auto &p : frequency)
        minHeap.push(new Node(p.first, p.second));

    while (minHeap.size() != 1)
    {

        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new Node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
    printCode(minHeap.top(), "");
<<<<<<< HEAD
    return minHeap.top();
=======
    return minHeaep.top();
>>>>>>> 78f67c15ea69e4971520aab185570aa16755f102
}
