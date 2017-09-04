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
	int count = 0;
	short int real_temp = 0;
	short int imag_temp = 0;
	while(infile.peek() != EOF){
		infile.read((char *) (& x), 2);
		i=i+2;
		infile.seekg(i);
		if(count==0){
			real_temp = x;
			count++;
		}
		else{
			imag_temp = x;
			complex<int> complexo(real_temp,imag_temp);
			count=0;
		}
	}
	infile.clear();
	infile.close();

	
	return(0);

}