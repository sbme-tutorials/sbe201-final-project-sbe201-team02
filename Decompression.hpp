#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

std::string Decomp(std::string input, Node *tree)
{
    int index = 0;
    std::string output;
    while (index < input.size())
    {
        Node *NodePtr = tree;
        while (NodePtr->left != NULL && NodePtr->right != NULL)
        {
            if (input[index] == '1')
            {
                NodePtr = NodePtr->right;
                index++;
            }
            else if (input[index] == '0')
            {
                NodePtr = NodePtr->left;
                index++;
            }
        }
        output.push_back( NodePtr->data );
    }

    return output;
}

