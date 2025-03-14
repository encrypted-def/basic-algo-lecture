// Authored by : audwns27
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/65c57b6c6f36477caf85d1f6b9c3e206
#include <bits/stdc++.h>
using namespace std;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int a, b, v;
  cin >> a >> b >> v;
  if((v-b) % (a-b) == 0) cout << (v-b) / (a-b);
  else cout << (v-b) / (a-b) + 1;
}

/*
2 1 1000000000과 같은 데이터를 생각한다면 매일 매일의 움직임을 정직하게 따라가는 방식으로 구현할 경우 시간초과가 남을 알 수 있다.
수학적으로 생각해보면 달팽이가 X일 동안 오른다고 하면 마지막 날은 A만큼, 나머지 날은 A-B만큼 오르기 때문에
(A-B) * (X-1) + A >= V이고, 이를 만족하는 가장 작은 X가 곧 답이 된다.

식을 풀어보면
(A-B) * (X-1) + A >= V
(A-B) * X - (A-B) + A >= V
(A-B) * X + B >= V
(A-B) * X >= (V-B)
X >= (V-B) / (A-B)
가 되고, (V-B)가 (A-B)로 나누어 떨어진다면 (V-B) / (A-B),
나누어 떨어지지 않는다면 (V-B) / (A-B) + 1이 답이 된다.
*/
