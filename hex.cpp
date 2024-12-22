#include "sig.h"
#include <iostream>
#include <fstream>
#include <string>

// next step: create signature database
// create signature check function

using namespace std;

int main(int argc, char *argv[]){
  string file_type;
  //unsigned char header[100];
  char header[100];

	if(argc!=2){
		cout << "The program takes a file path as input" << endl;
	}

	ifstream ifs(argv[1],ifstream::binary);
	if(ifs){
		
		filebuf* pbuf = ifs.rdbuf();
		size_t size = pbuf->pubseekoff (0,ifs.end,ifs.in);
		char buffer[size];
		pbuf->pubseekpos (0,ifs.in);
		pbuf->sgetn(buffer,100);
    /*for(int i=0;i<size;i++){
    	cout << hex << (int)(unsigned char)buffer[i] << " ";
    }*/
    
    for(int i=0;i<100;i++){
    	//header[i] = (unsigned char)buffer[i];
    	header[i] = buffer[i];
    }

    init_signature_data();
    file_type = check_signature(header);
    cout << "File format: " << file_type << endl;
	}
}