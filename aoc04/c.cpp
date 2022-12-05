#include <iostream>
#include <fstream>

using namespace std;

int main(){
  string l;
  ifstream f("input");

  int total = 0;
  int total2 = 0;

  while(getline(f,l)){
    int a,b,c,d;
    sscanf(l.c_str(),"%d-%d,%d-%d",&a,&b,&c,&d);
    if((a<=c && b >= d)||(c<=a && d>=b)) total++;
    if(((d>b)?d:b)-((a<c)?a:c) < b+d-c-a+1) total2++;
  }

  cout << total << endl;
  cout << total2 << endl;

  return 0;
}
