// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/51a6cef2473c4eb5ac5a3f9399afdc31
#include <bits/stdc++.h>
using namespace std;

int N, M, sg[500002], card[500002];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> sg[i];
  cin >> M;
  for (int i = 0; i < M; i++) cin >> card[i];
  sort(sg, sg + N);
  for (int i = 0; i < M; i++)
    cout << binary_search(sg, sg + N, card[i]) << ' ';
}

/*
굳이 card[i]로 저장하지 않고 각 카드를 매번 입력받으면서 바로 binary_search를 실행해도 됨
*/
