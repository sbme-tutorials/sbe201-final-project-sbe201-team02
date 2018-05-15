#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

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

 void HuffmanCodes(char data[], int freq[], int size)
    {
        struct Node *left, *right, *top;

        std::priority_queue<Node *, std::vector<Node *>, compare> minHeap;

        for (int i = 0; i < size; ++i)
            minHeap.push(new Node(data[i], freq[i]));

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
    }