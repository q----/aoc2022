#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

struct s{
  long long int x,y,bx,by;

  s(long long int xx, long long int yy, long long int bxx, long long int byy): x(xx),y(yy),bx(bxx),by(byy){};
};

long long int ab(long long int x){
  return (x<0)?-x:x;
}

long long int d(s a, long long int x, long long int y){
  return ab(a.x-x)+ab(a.y-y);
}

long long int d(s a){
  return d(a,a.bx,a.by);
}

int main(){
  string l;
  ifstream f("input");

  vector<s> scan;

  while(getline(f,l)){
    long long int x,y,bx,by;
    sscanf(l.c_str(),"Sensor at x=%lld, y=%lld: closest beacon is at x=%lld, y=%lld", &x, &y, &bx, &by);
    scan.push_back(s(x,y,bx,by));
  }

  set<long long int> lvl;
  long long int p2r = 0;

  for(auto a : scan){
    for(int i = 0; d(a,a.x+i,2000000)<=d(a); i++){
	    if(!(a.bx == a.x+i && a.by == 2000000))lvl.insert(a.x+i);
	    if(!(a.bx == a.x-i && a.by == 2000000))lvl.insert(a.x-i);
    }

    if(!p2r){
      vector<pair<long long int,long long int>> cand;
      for(int i = 0; i < d(a); i++){
              cand.push_back(pair<long long int, long long int>(a.x+d(a)-i+1,a.y+i));
              cand.push_back(pair<long long int, long long int>(a.x-d(a)+i-1,a.y-i));
              cand.push_back(pair<long long int, long long int>(a.x+i,a.y+d(a)-i+1));
              cand.push_back(pair<long long int, long long int>(a.x-i,a.y-d(a)+i-1));
      }
      for(auto x : cand){
              if(x.first > 4000000 || x.second > 4000000 || x.first < 0 || x.second < 0) continue;
              bool f = true;
              for(auto b : scan){
          	    if(d(b) >= d(b,x.first,x.second)){
          		    f = false;
          		    break;
          	    }
              }
              if(f){
          	    p2r = 4000000*x.first + x.second;
          	    break;
              }
      }
    }
  }

  cout << lvl.size() << endl;
  cout << p2r << endl;

  return 0;
}
