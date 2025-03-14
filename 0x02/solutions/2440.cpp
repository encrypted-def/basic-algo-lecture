// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/541d92f7657c4d088ec50462093bbc1b
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N;
  cin >> N;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N - i; j++)  cout << '*';
    cout << "\n";
  }
}
