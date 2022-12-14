#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

struct coor{
  int x;
  int y;

  coor(int xx, int yy):x(xx),y(yy){}
};

const bool operator<(const coor& lhs, const coor& rhs){
  if(lhs.x != rhs.x) return lhs.x < rhs.x;
  return lhs.y < rhs.y;
}

coor p(string l){
  int x,y;
  sscanf(l.c_str(),"%d,%d",&x,&y);
  return coor(x,y);
}

int main(){
  string l;
  ifstream f("input");

  set<coor> r;
  int maxy;

  while(getline(f,l)){
    stringstream s(l);
    string t;
    s>>t;
    coor start = p(t);
    maxy = (maxy > start.y)?maxy:start.y;
    r.insert(start);
    while(s>>t>>t){
      coor end = p(t);
      maxy = (maxy > end.y)?maxy:end.y;
      if(start.x == end.x){
        int p1 = (start.y < end.y)?start.y:end.y;
        int p2 = (start.y > end.y)?start.y:end.y;
        for(int i = p1; i <= p2; i++){
          r.insert(coor(start.x,i));
        }
      } else {
        int p1 = (start.x < end.x)?start.x:end.x;
        int p2 = (start.x > end.x)?start.x:end.x;
        for(int i = p1; i <= p2; i++){
          r.insert(coor(i,start.y));
        }
      }
      start = end;
    }
  }

  maxy += 2;

  for(int i = -1000; i <= 3000;i++){
    r.insert(coor(i,maxy));
  }

  coor s (500,0);
  int count = 0;

  while(s.y < 10000){
    if(!r.count(coor(s.x,s.y+1))){
        s.y++;
        continue;
    } else if(!r.count(coor(s.x-1,s.y+1))){
      s.x--;
      s.y++;
      continue;
    } else if(!r.count(coor(s.x+1,s.y+1))){
      s.x++;
      s.y++;
      continue;
    } else {
      r.insert(s);
      count++;
      if(s.y == 0 && s.x == 500) break;
      s = coor(500,0);
    }
  }

  cout << count << endl;
        

  return 0;
}
