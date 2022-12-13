#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool s(string a, string b){
  if(a == "") return true;
  if(b == "") return false;

  if(a[0] == ']' && b[0] != ']') return true;
  if(b[0] == ']' && a[0] != ']') return false;

  if(a[0] == '[' && b[0] >= '0' && b[0] <= '9'){
    if(b[1] == '0') return s(a.substr(1,string::npos),b.substr(0,2)+"]"+b.substr(2,string::npos));
    else return s(a.substr(1,string::npos),b.substr(0,1) + "]" + b.substr(1,string::npos));
  }

  if(b[0] == '[' && a[0] >= '0' && a[0] <= '9'){
    if(a[1] == '0') return s(a.substr(0,2)+"]"+a.substr(2,string::npos),b.substr(1,string::npos));
    else{
      return s(a.substr(0,1)+"]"+a.substr(1,string::npos),b.substr(1,string::npos));
    }
  }

  if(a[0] == '1' && a[1] == '0' && b[1] != '0') return false;
  if(b[0] == '1' && b[1] == '0' && a[1] != '0') return true;

  if(a[0] == b[0]) return s(a.substr(1,string::npos),b.substr(1,string::npos));

  return a[0] < b[0];
}

int main(){
  string l;
  ifstream f("input");

  int curr = 0;
  int total = 0;
  vector<string> lol;

  do{
    curr++;
    string g,h;
    getline(f,g);
    getline(f,h);
    if(s(g,h)){
      total+= curr;
    }
    lol.push_back(g);
    lol.push_back(h);
  }while(getline(f,l));

  cout << total << endl;

  lol.push_back("[[2]]");
  lol.push_back("[[6]]");

  sort(lol.begin(),lol.end(),s);

  int decode = 1;

  for(int i = 0; i < lol.size(); i++){
    if(lol[i] == "[[2]]"){
      decode *= (i+1);
    } else if(lol[i] == "[[6]]"){
      decode *= (i+1);
      break;
    }
  }

  cout << decode << endl;

  return 0;
}
