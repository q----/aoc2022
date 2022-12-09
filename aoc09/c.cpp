#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

struct pos{
  int x = 0;
  int y = 0;
};

const bool operator<(const pos& h, const pos& t){
  if(h.x != t.x) return h.x < t.x;
  return h.y < t.y;
}

int abs(int x){
  return (x>=0)?x:-x;
}

int d(pos h, pos t){ 
  return (abs(h.x-t.x) > abs(h.y-t.y))?abs(h.x-t.x):abs(h.y-t.y);
}

void m(pos& t, pos h){
  if(t.x > h.x)t.x--;
  else if(t.x<h.x) t.x++;

  if(t.y > h.y)t.y--;
  else if(t.y<h.y) t.y++;
}

void mh(pos& h, char dir){
  if(dir == 'R' || dir == 'L'){
    h.x += (dir=='R')?1:-1;
  } else if(dir == 'U' || dir == 'D'){
    h.y += (dir=='U')?1:-1;
  }
}

int main(){
  string l;
  ifstream f("input");

  vector<pos> r;
  for(int i = 0; i < 10; i++){
    pos x;
    r.push_back(x);
  }

  set<pos> v;
  set<pos> v2;

  v.insert(r[1]);
  v2.insert(r[9]);

  auto it = v.begin();
  auto it2 = v2.begin();

  while(getline(f,l)){
    char dir;
    int num;
    sscanf(l.c_str(), "%c %d",&dir, &num);

    for(int i = 0; i < num; i++){
      mh(r[0], dir);
      for(int j = 0; j < 10; j++){
        if(d(r[j],r[j+1]) > 1)m(r[j+1],r[j]);
      }
      it = v.insert(it,r[1]);
      it2 = v2.insert(it2,r[9]);
    }
  }

  cout << v.size() << endl;
  cout << v2.size() << endl;

  return 0;
}
