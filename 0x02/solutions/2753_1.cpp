// Authored by : -
// Co-authored by : -
//http://boj.kr/4b1e161ffc9b4281ab7dad4d1b6cbbd9
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
