// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/7b47d16a20b94095b78c693797ad2cab
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << popcount((unsigned int)(n ^ (-n)));
}
