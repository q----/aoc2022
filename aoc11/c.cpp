#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct m{
  queue<long long> it;

  char op;
  int n;

  int div;

  int t;
  int f;

  int insp = 0;

  m(queue<long long> i, char o, int num, int d, int tr, int fa) : it(i), op(o), n(num), div(d), t(tr), f(fa){}
};

int main(){
  for(int part = 0; part < 2; part++){
    string l;
    ifstream f("input");

    vector<m> monkeys;

    while(getline(f,l)){
      getline(f,l);
      for(int i = 0; i < l.size(); i++) if(l[i] == ',') l[i]=' ';
      queue<long long> i;
      stringstream s(l);
      string t;
      s >> t >> t;
      long long x;
      while(s >> x){
        i.push(x);
      }

      getline(f,l);
      char o;
      string q;
      stringstream s2(l);
      s2 >> t >> t >> t >> t >> o >> q;
      int num;
      if(q == "old") num = 0;
      else {
        num = stoi(q);
      }

      getline(f,l);
      int d;
      sscanf(l.c_str(),"  Test: divisible by %d", &d);

      getline(f,l);
      int tr;
      sscanf(l.c_str(),"    If true: throw to monkey %d", &tr);

      getline(f,l);
      int fa;
      sscanf(l.c_str(),"    If false: throw to monkey %d", &fa);

      getline(f,l);
      monkeys.push_back(m(i,o,num,d,tr,fa));
    }

    long long mod = 1;

    for(int i = 0; i < monkeys.size(); i++){
      mod *= monkeys[i].div;
    }

    int loop = (part)?10000:20;

    for(int i=0; i < loop; i++){
      for(int j = 0; j < monkeys.size(); j++){
        while(!monkeys[j].it.empty()){
          long long ob = monkeys[j].it.front();
          monkeys[j].it.pop();
          if(monkeys[j].op == '*'){
            if(monkeys[j].n == 0){
              ob *= ob;
            } else {
              ob *= monkeys[j].n;
            }
          } else {
            if(monkeys[j].n == 0){
              ob += ob;
            } else {
              ob += monkeys[j].n;
            }
          }
          if(!part) ob /= 3;
          if(ob % monkeys[j].div){
            monkeys[monkeys[j].f].it.push(ob%mod);
          } else {

            monkeys[monkeys[j].t].it.push(ob%mod);
          }
          monkeys[j].insp++;
        }
      }
    }

    vector<int> x;
    for(auto a: monkeys){
      x.push_back(a.insp);
    }

    sort(x.begin(),x.end());

    cout << ((long long)x[7]) * x[6] << endl;
  }

  return 0;
}
