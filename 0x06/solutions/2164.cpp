// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/de9183460fa945a69e8692510b3fd803
#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> q;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i = 1; i <= N; ++i) q.push(i);
  while(q.size() != 1){
    q.pop();
    int tmp = q.front();
    q.push(tmp);
    q.pop();
  }
  cout << q.front();
}
