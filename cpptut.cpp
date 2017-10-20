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

using namespace std;

size_t getFilesize(const char* filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

int main(int argc, char *argv[]){

	short int x = 0;
	const int NORMALIZER = 3;
	int fd = open(argv[1], O_RDONLY, 0);
	int i = 0;
	int count = 0;
	double real_temp = 0;
	double imag_temp = 0;
	size_t filesize = getFilesize(argv[1]);
	short int* mmappedData = (short int*) mmap(NULL, filesize, PROT_READ, MAP_PRIVATE | MAP_POPULATE, fd, 0);
	vector<short int> vectorMappedData;
	vectorMappedData.assign(mmappedData, mmappedData + filesize/sizeof(short int) );
	
	cout << "Tamanho do arquivo: " << filesize << "(elementos de 8 bit) " <<  endl;
	cout << "Tamanho do Vetor:   " << vectorMappedData.size() << "(elementos de 16 bits) " << endl;
	
	for(int i = 0; i< vectorMappedData.size();i++ ){
		x = vectorMappedData.at(i);
		if(i%2==0){
			real_temp = x;
		}
		else{
			imag_temp =x;
			complex<double> n_complex(real_temp,imag_temp);
			cout << "Real:     "<<real_temp << endl;
			cout << "Imag:     "<<imag_temp << endl;
			double abs_n_complex = abs(n_complex);
			double arg_n_complex = arg(n_complex);
			//cout << "Arg:      "<< arg_n_complex << endl;
			complex<double> n_complex_polar(abs_n_complex,arg_n_complex);
			double arg_compressed = round((arg_n_complex + M_PI)/(2*M_PI)*(NORMALIZER));
			complex<double> n_complex_polar_compressed(abs_n_complex,arg_compressed);
			//cout << "AgrComp:  "<<arg_compressed << endl;
			double arg_decompressed = (n_complex_polar_compressed.imag() *(2*M_PI))/(NORMALIZER)-M_PI;
			//cout << "ArgDecomp:"<< arg_decompressed << endl;
		}
	}
	
	return(0);
}