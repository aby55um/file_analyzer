#include "sig.h"
#include <iostream>
#include <fstream>

// next step: create signature database
// create signature check function

using namespace std;

int main(int argc, char *argv[]){
	if(argc!=2){
		cout << "The program takes a file path as input" << endl;
	}
	string text;
	ifstream ifs(argv[1],ifstream::binary);
	if(ifs){
		filebuf* pbuf = ifs.rdbuf();
		size_t size = pbuf->pubseekoff (0,ifs.end,ifs.in);
		char buffer[size];
		cout << "size: " << size << endl;
		pbuf->pubseekpos (0,ifs.in);
		pbuf->sgetn(buffer,100);
    /*for(int i=0;i<size;i++){
    	cout << hex << (int)(unsigned char)buffer[i] << " ";
    }*/
    init_signature_data();
    check_signature((int*)(unsigned char*)buffer);
	}
}