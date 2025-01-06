#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string,int[101]> sig_map;

//string check_signature(unsigned char* sig){
string check_signature(char sig_c[100]){
  unsigned char sig[100];
  for(int i=0;i<100;i++){
  	sig[i]=(unsigned char)sig_c[i];
  }
  int found = 0;	
  for(auto pair : sig_map){
  	//cout << pair.second[100] << endl;
  	for(int i=0;i<pair.second[100];i++){
  		//cout << pair.second[i] << "    " << (int)sig[i] << endl;
  		//cout << pair.first << endl;
  		/*if((int)sig[i]!=pair.second[i]){
  			//cout << "break" << endl;
  			break;
  		}*/
  		if((int)sig[i]==pair.second[i]){
  			found+=1;
  			if(found == pair.second[100]){
  				return pair.first;
  			}
  		}
  		else {
  			found = 0;
  			break;
  		}
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

  len = 5;
  int iso[5] = {0x43,0x44,0x30,0x30,0x31};
  for(int i=0;i<len;i++){
  	sig_map["ISO"][i] = iso[i];
  }
  sig_map["ISO"][100] = len;

  len = 8;
  int png[8] = {0x89,0x50,0x4e,0x47,0xd,0xa,0x1a,0xa};
  for(int i=0;i<len;i++){
  	sig_map["PNG"][i] = png[i];
  	//cout << hex << sig_map["PNG"][i] << endl;
  }
  sig_map["PNG"][100] = len;

  len = 1;
  int gpg[1] = {0x99};
  for(int i=0;i<len;i++){
  	sig_map["GPG"][i] = gpg[i];
  }
  sig_map["GPG"][100] = len;

  len = 2;
  int jpg[2] = {0xff,0xd8};
  for(int i=0;i<len;i++){
  	sig_map["JPG"][i] = jpg[i];
  }
  sig_map["JPG"][100] = len;
 
  len = 22;
  int deb[22] = {0x21,0x3c,0x61,0x72,0x63,0x68,0x3e,0xa,0x64,0x65,0x62,0x69,0x61,0x6e,0x2d,0x62,0x69,0x6e,0x61,0x72,0x79,0x2f};
  for(int i=0;i<len;i++){
  	sig_map["DEB"][i] = deb[i];
  }
  sig_map["DEB"][100] = 22;

  len = 3;
  int gz[3] = {0x1f,0x8b,0x8};
  for(int i=0;i<len;i++){
  	sig_map["GZ"][i] = gz[i];
  }
  sig_map["GZ"][100] = len;

  return 0;
}