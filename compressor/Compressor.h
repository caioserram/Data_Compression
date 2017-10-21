#ifndef COMPRESSOR_H
#define COMPRESSOR_H

class Compressor{
    public:
        Compressor(int normalizer);
        short int compress(double arg_z);
        double decompress(double arg_z);
        
    private:
        int normalizer;
};
#endif