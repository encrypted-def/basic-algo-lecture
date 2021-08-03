// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/d7b98a666ff14351a4dffae291de6951
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N;
  cin >> N;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= i; j++)  cout << '*';
    cout << "\n";
  }
}