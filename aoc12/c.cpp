#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

pair<int,int> find (char s, vector<string>& map){
  for(int i = 0; i < map.size(); i++){
    for(int j = 0; j < map[i].size(); j++){
      if(map[i][j] == s) return pair<int,int>(i,j);
    }
  }
  return pair<int,int>(-1,-1);
}

int main(){
  string l;
  ifstream f("input");

  vector<string> map;

  while(getline(f,l)){
    map.push_back(l);
  }

  vector<int> line;

  for(int i = 0; i < map[0].size();i++){
    line.push_back(-1);
  }

  vector<vector<int>> field;

  for(int i = 0; i < map.size(); i++) field.push_back(line);

  pair<int,int> start = find('S',map);
  
  map[start.first][start.second] = 'a';
  pair<int,int> end = find('E',map);
  map[end.first][end.second] = 'z';
  field[end.first][end.second] = 0;

  int curr = 0;

  while(field[start.first][start.second] == -1){
    curr++;
    for(int i = 0; i < map.size(); i++){
      for(int j = 0; j < map[i].size(); j++){
        if(field[i][j] != -1)continue;
        if((i != 0) && (field[i-1][j] != -1 && field[i-1][j] < curr) && (map[i-1][j] - map[i][j] <= 1)){
          field[i][j] = curr;
          continue;  
        }
        if((i != map.size()-1) && (field[i+1][j] != -1 && field[i+1][j] < curr) && (map[i+1][j] - map[i][j] <= 1)){
          field[i][j] = curr;
          continue;  
        }
        if((j != 0) && (field[i][j-1] != -1 && field[i][j-1] < curr) && (map[i][j-1] - map[i][j] <= 1)){
          field[i][j] = curr;
          continue;  
        }
        if((j != map[i].size()-1) && (field[i][j+1] != -1 && field[i][j+1] < curr) && (map[i][j+1] - map[i][j] <= 1)){
          field[i][j] = curr;
          continue;  
        }
      }
    }
  }

  cout << field[start.first][start.second] << endl;

  int min = field[start.first][start.second];

  for(int i = 0; i < map.size(); i++){
    for(int j = 0; j < map[i].size(); j++){
      if(map[i][j] == 'a' && field[i][j] < min && field[i][j] != -1){
        min = field[i][j];
      }
    }
  }

  cout << min << endl;

  return 0;
}
