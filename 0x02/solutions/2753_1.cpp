// Authored by : -
// Co-authored by : -
//http://boj.kr/c90b49f6a233442f8d300e0e4cd3a2e2
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int year;
  cin >> year;

  cout << chrono::year(year).is_leap();
}

/*
https://en.cppreference.com/w/cpp/chrono/year/is_leap
*/
