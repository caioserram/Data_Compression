#include "Huffman.h"

using namespace std;

map<unsigned char,int> Huffman::get_symbol_frequency(){
    map<unsigned char, int> symbols_freq;
    for(int i =0; i<this->symbols.size() ;i++){
        symbols_freq[symbols.at(i)]++;
    }
    return symbols_freq;
}

Huffman::Huffman(vector<unsigned char> symbols){
    this->symbols = symbols;
}