// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/782e418bd9b44cd5aad0d2937a82e873
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i = 0; i < N; i++) {
    int j = 0;
    for( ; j < i; j++)  cout << ' ';
    for( ; j < N; j++)  cout << '*';
    cout << "\n";
  }
}