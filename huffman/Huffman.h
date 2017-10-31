#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <map>
#include <vector>
using namespace std;    
    
class Huffman{
    public: 
        Huffman(vector<unsigned char> symbols);
        map<unsigned char,int> get_symbol_frequency();
    private: 
        vector<unsigned char> symbols; 
        
};
#endif