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

	while(infile.peek() != EOF){
		infile.read((char *) (& x), 2);
		infile.seekg(++i);
	}
	infile.clear();
	infile.close();

	
	return(0);

}