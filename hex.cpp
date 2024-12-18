#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	if(argc!=2){
		cout << "The program requires a file path" << endl;
	}
	string text;
	ifstream read_file(argv[1]);
	while(getline(read_file, text)){
		cout << text;
	}
}