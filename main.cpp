#include"Huff_code.hpp"
#include"Decompression.hpp"
int main()
    {
std::string input = "asjjdksfjk88899rrdedddsokooi';l'dfnds  j f  n djdddddfnsfndjnf";
    std::map<char, int> frequency;
    for (char Letter : input)
    {
        frequency[Letter]++;
    }

    std::cout<<"New codes:"<<std::endl;
    
    Node *tree = HuffmanCodes(frequency);
    std::cout<<std::endl;

    std::map< char , std::string > dictionary;
    makeDictionary( tree , "", dictionary );
    std::string code = encode( input , dictionary );

    std::cout<<"Compressed text:"<<std::endl<<code<<std::endl<<std::endl;

    std::string output = Decomp( code, tree);
    
    std::cout<<"Original text:"<<std::endl<<output<<std::endl<<std::endl;
    
    double ratio = input.size() / ( code.size() / 8);
    std::cout<<"Compretion ratio =  "<<input.size()<<"/"<<( code.size() / 8)<<" = "<<ratio<<std::endl;
    
    return 0;
    }