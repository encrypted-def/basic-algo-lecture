// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/043411fb280c4b0fbb3264fa5400f7a8
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int N;
  cin >> N;
    
  for(int i = N; i >= 1; i--){
    for(int j = 1; j <= N - i; j++) cout << ' ';
    for(int j = 1; j <= 2 * i - 1; j++) cout << '*';
    // '*'의 오른쪽 공백은 출력하지 말아야 통과합니다.
    cout << "\n";
  }
}