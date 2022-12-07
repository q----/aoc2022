#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct node{
  long long files = 0;
  vector<string> dirz;
};

string concat(vector<string> path){
  string o = "/";
  for(auto x : path){
    o += x + "/";
  }
  return o;
}

long long size(string dir, map<string,node>& dirs, map<string,long long>& sizes){
  if(sizes.count(dir)){
    return sizes[dir];
  }
  long long total = 0;
  for(auto a : dirs[dir].dirz){
    total += size(a,dirs,sizes);
  }
  sizes[dir] = total + dirs[dir].files;
  return sizes[dir];
}


int main(){
  string l;
  ifstream f("input");

  vector<string> pwd;
  map<string,node> dirs;

  while(getline(f,l)){
    if(l[0] == '$'){
      stringstream s(l);
      string t;
      s >> t >> t;
      if(t=="cd"){
        s >> t;
        if(t == "/") continue;
        if(t != ".."){
          pwd.push_back(t);
          node x;
          dirs.insert(pair<string,node>(concat(pwd),x));
        } else {
          pwd.pop_back();
        }
      }
      continue;
    }

    if(l[0] == 'd'){
      string str;
      stringstream s(l);
      s >> str >> str;

      dirs[concat(pwd)].dirz.push_back(concat(pwd)+str+"/");
    } else {
      long long x;
      string fn;
      stringstream s(l);
      s >> x >> fn;
      dirs[concat(pwd)].files += x;
    }
  }

  map<string,long long> sizes;

  size("/",dirs,sizes);

  long long total = 0;

  for(auto a : sizes){
    if(a.second <= 100000){
      total += a.second;
    }
  }
  
  cout << total << endl;

  long long goal = sizes["/"]-40000000;
  long long min = 70000000;

  for(auto a:sizes){
    if(a.second >= goal && a.second < min){
      min = a.second;
    }
  }

  cout << min << endl;

  return 0;
}
