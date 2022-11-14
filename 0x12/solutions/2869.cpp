// Authored by : audwns27
// Co-authored by : -
// http://boj.kr/a9eb8b5b0eea4c5aaa2ffd3331ec2208

#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int day, night, height;
  cin >> day >> night >> height;

  cout << (height - night -1) / (day-night) + 1;

  return 0;
}
