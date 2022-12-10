#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



int main(){
  string l;
  ifstream f("input");

  vector<bool> screen;

  for(int i = 0; i <240; i++) screen.push_back(false);
  screen[0]=true;

  int s = 1;
  int c = 1;
  int o = 0;

  while(getline(f,l)){
    int x;
    int p = 0;
    if(l != "noop"){
      sscanf(l.c_str(),"addx %d",&x);
      p++;
      s+=x;
    }

    for(int i = 0; i <= p; i++){
      if(++c == 20 || c == 60 || c == 100 || c==140 || c==180 || c== 220){
        o += c*(s-(p-i)*x);
      }
      int t = s-(p-i)*x;
      if((uint32_t)(((c-1)%40)-t+ 1)<= 2) screen[c-1] = true;
    }
  }

  cout << o << endl;

  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 40; j++){
      cout << ((screen[40*i+j])?'#':'.');
    }
    cout << endl;
  }

  return 0;
}
