#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  string l;
  ifstream f("input");

  int total = 0;
  vector<int> max;

  while(getline(f,l)){
    if(l== ""){
      max.push_back(total);
      total = 0;
      if(max.size() <= 3) continue;
      sort(max.begin(),max.end());
      max.erase(max.begin());
      continue;
    }
    stringstream s(l);
    int i;
    s >> i;
    total += i;
  }

  max.push_back(total);
  sort(max.begin(),max.end());
  max.erase(max.begin());

  cout << max[2] << endl;

  cout << max[0]+max[1]+max[2] << endl;
  return 0;
}
