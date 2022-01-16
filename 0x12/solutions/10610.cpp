// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/8e68f1b3f5684e9ca58fb356ea86aa2f
#include <bits/stdc++.h>
using namespace std;

string N;
vector<int> nums;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (char c : N)
    nums.push_back(c - '0');

  sort(nums.begin(), nums.end(), greater<int>());
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum % 3 == 0 && nums.back() == 0)
    for (int n : nums) cout << n;
  else
    cout << -1;
}
/*
30의 배수가 되려면 10의 배수인 동시에 3의 배수이어야 합니다.
10의 배수는 숫자 안에 0이 존재하는지로 판별하고,
3의 배수는 각 숫자의 자릿수의 합이 3의 배수인지로
판별할 수 있습니다.
만약 30의 배수가 될 수 있음이 확인된다면,
큰 숫자부터 출력합니다.
*/
