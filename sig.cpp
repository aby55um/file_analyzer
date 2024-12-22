#include <iostream>
#include <map>
#include <string>

using namespace std;

//map<string,int*> sig_map;
map<string,int[101]> sig_map;

//string check_signature(unsigned char* sig){
string check_signature(char sig[100]){	
	//cout << "sig " << sizeof(sig[0]) << " " << sizeof(sig) << endl;
  /*for(int i=0;i<sizeof(sig)/sizeof(sig[0]);i++){
  	cout << (int)sig[i] << endl;
  }*/
  //cout << sig_map["PDF"][0] << endl;
  /*for(auto pair : sig_map){
    if(sizeof(sig)/sizeof(sig[0])>=sizeof(pair.second)/sizeof(pair.second[0])){
      for(int i=0;i<sizeof(pair.second)/sizeof(pair.second[0]);i++){
        //cout << (int)sig[i] << " " << pair.second[i] << endl;
        //cout << hex << pair.second[i] << endl;
        cout << pair.second[0] << "  " << sig[i] << endl;
        if((int)sig[i]!=pair.second[i]){
        	break;
        }
        return pair.first;
      }
  	}
  }*/
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
  //sig_map["PDF"] = test;
  /*for(int i=0;i<=sizeof(sig_map["PDF"])/sizeof(sig_map["PDF"][0])+1;i++){
  	cout << hex << sig_map["PDF"][i] << " ";
  }*/
  //cout << "test" << sizeof(((unsigned char*)test)[0]) << " " << sizeof((unsigned char*)test) << endl;
  /*for(int i=0;i<sizeof(test)/sizeof(test[0]);i++){
  	cout << test[i] << endl;
  }*/
  return 0;
}


