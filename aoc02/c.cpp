#include <iostream>
#include <fstream>

using namespace std;

int main(){
  string l;
  ifstream f ("input");

  int total = 0;
  int total2 = 0;

  while(getline(f,l)){
    total += ((l[2]-l[0]-1)%3)*3 + (l[2]-'W');
    total2 += ((l[2]-'X')*3) + ((l[2]-'X'+l[0])%3)+1;
  }

  cout << total << endl;
  cout << total2 << endl;

  return 0;
}
    
