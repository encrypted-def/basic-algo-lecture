// http://boj.kr/dd17192cc3974a78a2d4b6980f4bdd10
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string t, p;
  getline(cin, t);
  getline(cin, p);
  int cnt = 0; 
  int f = t.find(p);
  while(f != string::npos){
    cnt++;
    f = t.find(p, f + p.size());
  }
  cout << cnt;
}
