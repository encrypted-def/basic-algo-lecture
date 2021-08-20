// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/d1ba3e452d8842d7a9e56640231e25f5
#include <bits/stdc++.h>
using namespace std;

const int MXN = 4000002;
vector<bool> seive(MXN, true);
vector<int> primes;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i=2; i*i<MXN; i++){
    if (!seive[i]) continue;
    for (int j = i * i; j < MXN; j += i) 
      seive[j] = false;
  }
  for (int i = 2; i < MXN; i++) if (seive[i]) primes.push_back(i);
  primes.push_back(0);

  int target, s = 0, e = 1, ans = 0, tmpSum = primes[0];
  cin >> target;
  while (1) {
    if (tmpSum == target) ans++;
    if (tmpSum <= target) tmpSum += primes[e++];
    if (target < tmpSum) tmpSum -= primes[s++];
    if (e == int(primes.size())) break;
  }
  cout << ans;
}
