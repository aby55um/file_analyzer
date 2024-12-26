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
  int pdf[4] = {0x25,0x50,0x44,0x46};
  for(int i=0;i<len;i++){
  	sig_map["PDF"][i] = pdf[i];
  }
  sig_map["PDF"][100] = len;
  
  int zip[4] = {0x50,0x4b,0x03,0x04};
  for(int i=0;i<len;i++){
  	sig_map["ZIP"][i] = zip[i];
  }
  sig_map["ZIP"][100] = len;

  int elf[4] = {0x7f,0x45,0x4c,0x46};
  for(int i=0;i<len;i++){
  	sig_map["ELF"][i] = elf[i];
  }
  sig_map["ELF"][100] = len;

  len = 3;
  int mp3[3] = {0x49,0x44,0x33};
  for(int i=0;i<len;i++){
  	sig_map["MP3"][i] = mp3[i];
  }
  sig_map["MP3"][100] = len;
  
  return 0;
}


