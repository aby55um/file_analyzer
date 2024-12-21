#include <iostream>
#include <map>
#include <string>

using namespace std;

int check_signature(int* sig){
  
  return 0;
}

map<string,int*> sig_map;

int init_signature_data(){
  int test[4] = {0x25,0x50,0x44,0x46};
  sig_map["PDF"] = test;
  for(int i=0;i<=sizeof(sig_map["PDF"])/sizeof(sig_map["PDF"][0])+1;i++){
  	cout << hex << sig_map["PDF"][i] << " ";
  }
  cout << endl;
  return 0;
}


