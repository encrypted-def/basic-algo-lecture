#include <bits/stdc++.h>
using namespace std;

int main(void){
  pair<int,int> t1 = make_pair(10, 13);
  pair<int,int> t2 = {4, 6}; // C++11
  cout << t2.first << ' ' << t2.second << '\n'; // 4 6
  if(t2 < t1) cout << "t2 < t1"; // t2 < t1
}
