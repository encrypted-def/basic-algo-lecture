// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/21a8fd913e464741a83d08770669ffdc
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int N;
  cin >> N;
    
  for(int i = 1; i <= N - 1; i++) {
    for(int j = 1; j <= N - i; j++) cout << ' ';
    for(int j = 1; j <= 2 * i - 1; j++) cout << '*';
    // '*'의 오른쪽 공백은 출력하지 말아야 통과합니다.
    cout << "\n";
  }
    
  for(int j = 1; j <= 2 * N - 1; j++) cout << '*';
  cout << "\n";
    
  for(int i = N - 1; i >= 1; i--) {
    for(int j = 1; j <= N - i; j++) cout << ' ';
    for(int j = 1; j <= 2 * i - 1; j++) cout << '*';
    // '*'의 오른쪽 공백은 출력하지 말아야 통과합니다.
    cout << "\n";
  }
}