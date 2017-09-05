#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <complex>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

	short int x = 0;

	ifstream infile;
	infile.open(argv[1], ios::binary | ios::in);
	int i = 0;
	//guarantees that the number are being read in an alternate manner
	int count = 0;
	double real_temp = 0;
	double imag_temp = 0;
	while(infile.peek() != EOF){
		//reads 2 bytes from file
		infile.read((char *) (& x), 2);
		i=i+2;
		infile.seekg(i);
		if(count==0){
			real_temp = x;
			count++;
		}
		else{
			// create complex number 
			imag_temp =x;
			complex<double> n_complex(real_temp,imag_temp);
			//converts n_complex to polar notation
			double abs_n_complex = abs(n_complex);
			double arg_n_complex = arg(n_complex);
			complex<double> n_complex_polar(abs_n_complex,arg_n_complex);
			//here, it should convert the angle to be between 0 and 3
			//save it to a output
			count=0;
		}
	}
	infile.close();
	return(0);
}