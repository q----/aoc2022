#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
  string l;
  ifstream f ("input");

  vector<string> trees;

  while(getline(f,l))trees.push_back(l);

  int total = 0;
  int max = 0;

  for(int i = 0; i < trees.size(); i++){
    for(int j = 0; j < trees[i].size(); j++){
      bool v = false;
      bool f = true;
      int score = 1;
      int tmp = 0;
      for(int k = i-1; k >= 0; k--){
        tmp++;
        if(trees[k][j] >= trees[i][j]){
          f = false;
          break;
        }
      }
      v = f || v;
      f = true;
      score *= tmp;
      tmp = 0;

      for(int k = i+1; k < trees.size(); k++){
        tmp++;
        if(trees[k][j] >= trees[i][j]){
          f = false;
          break;
        }
      }
      v = f|| v;
      f = true;
      score *= tmp;
      tmp = 0;

      for(int k = j-1; k >= 0; k--){
        tmp++;
        if(trees[i][k] >= trees[i][j]){
          f = false;
          break;
        }
      }
      v = f|| v;
      f = true;
      score *= tmp;
      tmp = 0;

      for(int k = j+1; k < trees[i].size(); k++){
        tmp++;
        if(trees[i][k] >= trees[i][j]){
          f = false;
          break;
        }
      }
      if(f||v)total++;
      score *= tmp;
      if(score > max) max = score;
    }
  }

  cout << total << endl;
  cout << max << endl;

  return 0;
}
