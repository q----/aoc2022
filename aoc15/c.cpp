#include <iostream>
#include <fstream>
#include <vector>

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
  const long long int level = 2000000;
  //const long long int level = 10;
  string l;
  ifstream f("input");

  

  vector<s> scan;
  long long int xmax= -1000000;
  long long int xmin = 100000000000;


  while(getline(f,l)){
    long long int x,y,bx,by;
    sscanf(l.c_str(),"Sensor at x=%lld, y=%lld: closest beacon is at x=%lld, y=%lld", &x, &y, &bx, &by);
    xmin = (xmin < x)?xmin:x;
    xmax = (xmax > x)?xmax:x;
    scan.push_back(s(x,y,bx,by));
  }

//  cout << xmin << "\t" << xmax << endl;
//  long long int count = 0;
//
//  for(int i = xmin; i <= xmax; i++){
//    for(auto a : scan){
//      if(d(a) >= d(a,i,level)){
//        count++;
//        break;
//      }
//    }
//  }
//
//
//  bool flag = true;
//
//  while(flag){
//    flag = false;
//    xmin--;
//    for(auto a : scan){
//      if(d(a) >= d(a,xmin,level)){
//        flag = true;
//        break;
//      }
//    }
//    count++;
//  }
//
//  flag = true;
//  while(flag){
//    flag = false;
//    xmax++;
//    for(auto a : scan){
//      if(d(a) >= d(a,xmax,level)){
//        flag = true;
//        break;
//      }
//    }
//    count++;
//  }
//
//  cout << count << endl;

  for(long long int i = 0; i <= 4000000; i++){
    for(long long int j = 0; j <= 4000000; j++){
      bool flag = true;
      for(auto a : scan){
        if(d(a)>= d(a,i,j)){
          flag = false;
          break;
        }
      }
      if(flag){
        cout << (i * 4000000 + j) << endl;
        return 0;
      }
    }
  }
  return 0;
}
