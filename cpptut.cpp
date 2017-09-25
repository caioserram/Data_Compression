#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <complex>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

	short int x = 0;
	const int NORMALIZER = 4;
	ifstream infile;
	infile.open(argv[1], ios::binary | ios::in);
	int i = 0;
	int count = 0;
	double real_temp = 0;
	double imag_temp = 0;
	while(infile.peek() != EOF){
		infile.read((char *) (& x), 2);
		i=i+2;
		infile.seekg(i);
		if(count==0){
			real_temp = x;
			count++;
		}
		else{
			imag_temp =x;
			complex<double> n_complex(real_temp,imag_temp);
			cout << "Real:     "<<real_temp << endl;
			cout << "Imag:     "<<imag_temp << endl;
			double abs_n_complex = abs(n_complex);
			double arg_n_complex = arg(n_complex);
			cout << "Arg:      "<< arg_n_complex << endl;
			complex<double> n_complex_polar(abs_n_complex,arg_n_complex);
			double arg_compressed = round((arg_n_complex + M_PI)/(2*M_PI)*(NORMALIZER-1));
			complex<double> n_complex_polar_compressed(abs_n_complex,arg_compressed);
			cout << "AgrComp:  "<<arg_compressed << endl;
			count=0;
		}
	}
	infile.close();
	
	return(0);
}