#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string,int[101]> sig_map;

//string check_signature(unsigned char* sig){
string check_signature(char sig[100]){	
  for(auto pair : sig_map){
  	for(int i=0;i<pair.second[100];i++){
  		if((int)sig[i]!=pair.second[i]){
  			break;
  		}
  		return pair.first;
  	}
  }
  return "No file signature found";
}

int init_signature_data(){
	int len = 4;
  int test[4] = {0x25,0x50,0x44,0x46};
  for(int i=0;i<len;i++){
  	sig_map["PDF"][i] = test[i];
  }
  sig_map["PDF"][100] = 4;
  return 0;
}


