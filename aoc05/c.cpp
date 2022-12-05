#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

int main(){
  string l;
  ifstream f ("input");

  vector<stack<char>> x;

  for(int i = 0; i < 9; i++){
    stack<char> q;
    x.push_back(q);
  }


  while(getline(f,l)){
    if(l[0] != '['){
      getline(f,l);
      break;
    }
    for(int i = 0; i < 9; i++){
      if(l[4*i+1] != ' ') x[i].push(l[4*i+1]);
    }
  }

  vector<stack<char>> g;
  vector<stack<char>> g2;

  for(int i = 0; i < 9; i++){
    stack<char> q;
    stack<char> q2;
    while(!x[i].empty()){
      q.push(x[i].top());
      q2.push(x[i].top());
      x[i].pop();
    }
    g.push_back(q);
    g2.push_back(q2);
  }

  while(getline(f,l)){
    int k,a,b;
    sscanf(l.c_str(),"move %d from %d to %d",&k,&a,&b);

    stack<char> crane;
    for(int i = 0; i < k; i++){
      char c = g[a-1].top();
      g[b-1].push(c);
      g[a-1].pop();

      char c2 = g2[a-1].top();
      crane.push(c2);
      g2[a-1].pop();
    }
    
    while(!crane.empty()){
      g2[b-1].push(crane.top());
      crane.pop();
    }

  }

  for(int i = 0; i < 9; i++){
    cout << g[i].top();
  }
  cout << endl;

  for(int i = 0; i < 9; i++){
    cout << g2[i].top();
  }
  cout << endl;

  return 0;
}


