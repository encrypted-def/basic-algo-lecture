// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/e506f4f9f3074de293fcde43c4a45208
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N;
  cin >> N;

  for(int i = 0; i < N; i++) {
    int j = 0;
    for( ; j < N - i - 1; j++)  cout << ' ';
    for( ; j < N; j++)  cout << '*';
    cout << "\n";
  }
}