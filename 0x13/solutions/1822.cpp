// Authored by : unluckyjung
// Co-authored by : -
// http://boj.kr/b569f45926cd477d8a56d73c1538657f
#include <bits/stdc++.h>

using namespace std;

vector<int> nums1, nums2;

void solve() {
  vector<int> answer;
  for (const int &num : nums1) {
    if (binary_search(nums2.begin(), nums2.end(), num)) continue;
    answer.push_back(num);
  }

  cout << answer.size() << "\n";
  for (const int &num : answer) {
    cout << num << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int num1Count, num2Count;
  cin >> num1Count >> num2Count;

  int num;
  for (int i = 0; i < num1Count; ++i) {
    cin >> num;
    nums1.push_back(num);
  }

  for (int i = 0; i < num2Count; ++i) {
    cin >> num;
    nums2.push_back(num);
  }

  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());

  solve();

  return 0;
}