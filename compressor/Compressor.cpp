#include "Compressor.h"
#include <cmath>

using namespace std;

short int Compressor::compress(double arg_z){
    return round((arg_z + M_PI)/(2*M_PI)*(this->normalizer));
}

double Compressor::decompress(double arg_z){
    return (arg_z *(2*M_PI))/(this->normalizer)-M_PI;
}

Compressor::Compressor(int normalizer){
    this->normalizer = normalizer;
}