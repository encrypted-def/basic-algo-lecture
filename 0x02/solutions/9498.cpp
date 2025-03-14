// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/b077642563084c938e85e4396993fd6b
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int score;
  cin >> score;
    
  if(90 <= score && score <= 100)  cout << 'A';
  else if(80 <= score)  cout << 'B';
  else if(70 <= score)  cout << 'C';
  else if(60 <= score)  cout << 'D';
  else cout << 'F';
}