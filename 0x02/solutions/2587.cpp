// Authored by : wogha95
// Co-authored by : -
// http://boj.kr/3f4f42b54653435ab38e16a902368184
#include <bits/stdc++.h>
using namespace std;

int num[5], total;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for(int i = 0; i < 5; i++) cin >> num[i];
    
  // 평균
  for(int i = 0; i < 5; i++) total += num[i];
  cout << total / 5 << "\n";
    
  // 중앙값
  sort(num, num + 5);
  cout << num[2];
}