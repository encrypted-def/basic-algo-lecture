// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/a58442b57f6140b78d8f3a07f2bbc5bb
#include <bits/stdc++.h>
using namespace std;

const int M = 360'000;
const int MX = 200'000 + 2;

int a[MX], b[MX];
int n;

vector<int> failure() {
  vector<int> f(n);
  int j = 0;
  for(int i = 1; i < n; i++) {
    while(j > 0 && a[i] != a[j]) j = f[j - 1];
    if(a[i] == a[j]) f[i] = ++j;
  }
  return f;
}

bool is_matched() {
  vector<int> fa = failure();

  int j = 0;
  for(int i = 0; i < 2*n - 1; i++) {
    int ci = i;
    if(ci >= n) ci -= n;
    while(j > 0 && b[ci] != a[j]) j = fa[j - 1];
    if(b[ci] == a[j]) j++;
    if(j == n) return 1;
  }
  return 0;
}

void setup() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  sort(a, a + n);
  sort(b, b + n);

  a[n] = a[0] + M;
  b[n] = b[0] + M;

  for(int i = 0; i < n; i++) {
    a[i] = a[i + 1] - a[i];
    b[i] = b[i + 1] - b[i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  
  if(is_matched()) cout << "possible";
  else cout << "impossible";
}
/*
원형 패턴 내에서 각도 차이가 동일한 패턴을 찾는 문제라고 재정의하자.

setup 함수는 각도를 입력 받아 정렬한 뒤
가장 작은 각도에 360,000을 더한 값을 n번째 인덱스로 추가한다.
이후 앞뒤 각도의 차이를 배열 a, b에 각각 저장한다.

is_matched 함수는 아래와 같이 동작한다.
a에 대한 실패함수 fa를 구한다. 이후 a와 b를 매칭한다.
원형 패턴이므로, 시작 인덱스가 0일 때부터 (n - 1)일 때까지 매칭을 시도한다.

시작 인덱스가 i이어서 증가하던 중 (n - 1)보다 커져 n이 된 경우,
다시 0으로 돌아가도록 구현한다(29번째 줄).
이렇게 ci를 실제 b배열 상에서 가리키는 인덱스로 활용한다.
이같이 설정하는 경우, 인덱스 i는 0부터 2*n - 2까지 증가해야 한다.

a[ci]와 b[j]를 실패함수를 활용해 매칭하면서
j가 n이 되면 패턴을 찾은 것이므로 1을,
j가 n이 되지 못한 채 매칭 시도가 끝나면 0을 반환한다.
*/