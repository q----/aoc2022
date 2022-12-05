#include <iostream>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int prio (char x){
  return (x <='Z')?x-'A'+27:x-'a'+1;
}

int aa (string l){
  for(int i = 0; i < l.size()/2;i++){
    for(int j = l.size()/2; j < l.size();j++){
      if(l[i] == l[j]){
        return prio(l[i]);
      }
    }
  }
  return 0;
}

int main(){
  string l;
  ifstream f("input");

  int total = 0;
  int total2 = 0;
  map<char,int> a;
  int count = 0;
  
  while(getline(f,l)){
    total += aa(l);
    set<char> x;
    for(char c : l) x.insert(c);

    for(auto c : x) a[c]++;

    int check = 0;
    for(auto c : a){
      check += c.second;
    }

    if(!(++count%3)){
      for(auto c : a){
        if(c.second == 3){
          total2 += prio(c.first);
          break;
        }
      }
      a.clear();
    }
  }

  cout << total << endl;
  cout << total2 << endl;

  return 0;

}
