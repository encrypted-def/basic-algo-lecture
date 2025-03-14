// Authored by : unluckyjung
// Co-authored by : -
// http://boj.kr/9a310c28f35f4ecab441c986fe684050

#include <bits/stdc++.h>
using namespace std;

int dishesCount, sushiKindCount, chainingEatCount, couponNum;
int dishes[30001 * 2];
int ateCount[3001];
int ateKindCount;
int answer;

void eat(int sushi) {
  if (ateCount[sushi] == 0) {
    ateKindCount++;
    answer = max(answer, ateKindCount);
  }
  ateCount[sushi]++;
}

void overeat(int sushi) {
  ateCount[sushi]--;
  if (ateCount[sushi] == 0) ateKindCount--;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> dishesCount >> sushiKindCount >> chainingEatCount >> couponNum;
  ateCount[couponNum]++;
  ateKindCount = 1;
  answer = 1;

  for (int i = 0; i < dishesCount; ++i) {
    cin >> dishes[i];
    dishes[dishesCount + i] = dishes[i];
  }

  for (int i = 0; i < dishesCount * 2; ++i) {
    if (i >= chainingEatCount) overeat(dishes[i - chainingEatCount]);
    eat(dishes[i]);
  }
  cout << answer;

  return 0;
}