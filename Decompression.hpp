#include <iostream>
#include <queue>
#include <string>
#include <map>

std::string encode(std::string input, std::map<char, std::string> dictionary)
{
    int index=0;
    std::string compressedText;
    while ( index < input.size())
    {
        std::string newCode = dictionary.find(input[index])-> second;
        index++;
        compressedText = compressedText + newCode;
    }
    return compressedText;
}



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


void makeDictionary(Node *root, std::string str, std::map< char , std::string > &dictionary )
{
    if (root == nullptr)
        return;

    else  if (root->data == '$')
    {
        makeDictionary(root->left, str + "0", dictionary);
        makeDictionary(root->right, str + "1", dictionary);
    }

    else if (root->data != '$')
    {
        dictionary.insert ( std::pair<char,std::string>(root->data,str) );
        makeDictionary(root->left, str + "0", dictionary);
        makeDictionary(root->right, str + "1", dictionary);
    }
}

