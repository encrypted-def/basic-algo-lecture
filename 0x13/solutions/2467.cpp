// Authored by : qhsl1213
// Co-authored by : -
// http://boj.kr/0f9cefb59fc547539a97b79081df10f7
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solution[100000];
ll cur_zero_closed = INT_MAX;
pair<ll, ll> answer;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for(int i=0; i<N; i++)
    cin >> solution[i];
  int st = 0;
  int en = N-1;
  while(st < en){
    if(cur_zero_closed > abs(solution[st]+solution[en])){
      cur_zero_closed = abs(solution[st]+solution[en]);
      answer = {solution[st], solution[en]};
    }
    ll cmp1 = abs(solution[st] + solution[en-1]);
    ll cmp2 = abs(solution[st+1] + solution[en]);
    if(cmp1 <= cmp2) en = en - 1;
    else st = st + 1;
  }
  cout << answer.first << " " << answer.second;
}