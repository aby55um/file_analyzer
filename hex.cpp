#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	if(argc!=2){
		cout << "The program takes a file path as input" << endl;
	}
	string text;
	ifstream ifs(argv[1],ifstream::binary);
	/*while(getline(ifs, text)){
		cout << text;
	}*/
	filebuf* pbuf = ifs.rdbuf();
	size_t size = pbuf->pubseekoff (0,ifs.end,ifs.in);
	pbuf->pubseekpos (0,ifs.in);
	cout << size << endl;
}