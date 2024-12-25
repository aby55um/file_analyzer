#include <string>
#include <iostream>
using namespace std;

string file_analysis(string file_type, char buffer[], size_t size){
	if(file_type == "PDF"){
		int n=0;
		for(int i=0;i<size;i++){
			if(buffer[i]==0x6f && buffer[i+1]==0x62 && buffer[i+2]==0x6a && buffer[i+3]==0x0d && buffer[i+4]==0x0a && buffer[i+5]==0x3c && buffer[i+6]==0x3c){
				n++;
        int k=i+8;
        cout << "object " << n << ": ";
        //while(buffer[k]!=0x2f){
        while(buffer[k]!=0x3e){
        	cout << buffer[k];
        	k++;
        	/*if(k>i+200){
        		break;
        	}*/
        }
        cout << endl;
				//cout << j << "-th obj found at " << i << endl;
			}
		}
	}
  return "test";
}