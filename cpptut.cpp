#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <complex>
#include <cmath>
#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>
#include "compressor/Compressor.h"

using namespace std;

size_t getFilesize(const char* filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

int main(int argc, char *argv[]){

	const int NORMALIZER = 3;
	int fd = open(argv[1], O_RDONLY, 0);
	
	//mapping file to vector routine 
	size_t filesize = getFilesize(argv[1]);
	short int* mmappedData = (short int*) mmap(NULL, filesize, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
	vector<short int> vectorMappedData;
	vectorMappedData.assign(mmappedData, mmappedData + filesize/sizeof(short int) );
	
	//cout << "Tamanho do arquivo: " << filesize << "(elementos de 8 bit) " <<  endl;
	//cout << "Tamanho do Vetor:   " << vectorMappedData.size() << "(elementos de 16 bits) " << endl;
	//cout << "Numero de pares:    " << vectorMappedData.size()/2 << "(2 elementos de 16 bits) " << endl;
	
	for(int i = 0; i< vectorMappedData.size();i+=2 ){
		
		complex<double> z(vectorMappedData.at(i),vectorMappedData.at(i+1));
		
		complex<double> z_polar(abs(z),arg(z));
		
		//cout << "Real:     "<<real_temp << endl;
		//cout << "Imag:     "<<imag_temp << endl;
		//cout << "Arg:      "<< arg_z << endl;
		
		Compressor compressor(NORMALIZER);
		
		short int arg_z_compressed = compressor.compress(z_polar.imag());
		
		complex<double> z_polar_compressed(abs(z),arg_z_compressed);
		
		double arg_z_decompressed = compressor.decompress(z_polar_compressed.imag());
		
		//cout << "AgrComp:     "<<arg_z_compressed << endl;
		//cout << "ArgDecomp:"<< arg_z_decompressed << endl;
	}
	
	return(0);
}