// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/1f4d8438f46a4078bbfe1bdd2ab092e5
#include <bits/stdc++.h>
using namespace std;

string s[2];
int p[4002][4002];
int cnt[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2,
             2, 1, 2, 2, 1, 2, 2, 2, 1, 2,
             1, 1, 1, 2, 2, 1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s[0] >> s[1];

  int cur_idx = 0;
  int sz = s[0].size();
  for(int i = 0; i < sz; i++) {
    p[cur_idx++][0] = cnt[s[0][i] - 'A'];
    p[cur_idx++][0] = cnt[s[1][i] - 'A'];
  }

  int len = sz*2;
  int cycle = len - 2;
  for(int cur = 0; cur < cycle; cur++) {
    len--;
    for(int i = 0; i < len; i++)
      p[i][cur + 1] = (p[i][cur] + p[i + 1][cur]) % 10;
  }
  cout << p[0][sz*2 - 2] << p[1][sz*2 - 2];
}
/*
s[0]에는 이름 A를 기록하고, s[1]에는 이름 B를 기록한다.
p 배열엔 각 이름 문자들의 획수를 번갈아가며 기록한다.
이는 21-24번째 줄과 같이 구현한다.

p 배열을 4000x4000으로 선언해도 메모리 제한에 걸리지 않는다.
따라서, 4002x4002로 선언하고 이전 인덱스를 확인하며 다음 값을 계산한다.

len은 현재 사이클에서 계산해야 하는 p배열의 유효 길이이다.
한 번 사이클을 돌 때마다 길이가 1 감소하므로,
2개 원소를 남기기 위해선 len - 2번 사이클을 돌아야 한다.
따라서 26-33번 줄과 같이 반복문을 구현한다.

부가적으로, p 배열의 값은 현 인덱스와 다음 인덱스를 제외하면
전혀 저장해둘 필요가 없기 때문에,
p 배열을 4002x2로 선언한 뒤, 인덱스를 0과 1로만 바꾸면서 연산할 수 있다.
이 경우 메모리와 실행시간 모두 크게 감소한다.
참고 코드: http://boj.kr/20ee9f15523343309b415fbb9b79cf56
*/