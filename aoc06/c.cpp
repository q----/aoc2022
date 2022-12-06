#include <iostream>
#include <fstream>
#include <set>


using namespace std;

int main(){
  string l;
  ifstream f ("input");
  getline(f,l);
  int sop = 0;
  int som = 0;

  for(int i = 0; i < l.size();i++){
    set<char> x;
    for(int j = 0; j < 4; j++){
      if(!(x.insert(l[i+j]).second)) break;
    }
    if(x.size() < 4)continue;
    if(!sop && x.size() == 4){
      sop = i+4;
    }
    for(int j = 4; j < 14; j++){
      if(!(x.insert(l[i+j]).second)) break;
    }
    if(x.size() == 14){
      som = i+14;
      break;
    }
  }

  cout << sop << endl; 
  cout << som << endl;

  return 0;
}
