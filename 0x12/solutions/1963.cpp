// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/db8b8c85ca584c5fb3250b395bc7e678
#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve(10002, true);

int vec2num(vector<int> &vec) {
  int r = 0;
  int p10 = 1;
  for (int i = 0; i < 4; i++){
    r += vec[i] * p10;
    p10 *= 10;
  }
  return r;
}

vector<int> num2vec(int num){
  vector<int> rtn;
  do rtn.push_back(num % 10);
  while (num /= 10);
  return rtn;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  sieve[1] = false;
  for (int i = 2; i * i < 10000; i++)
    for (int j = i * i; j < 10000; j += i) sieve[j] = false;

  int tc, s, e;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    cin >> s >> e;
    queue<int> Q;
    Q.push(s);
    int dist[10004];
    fill(dist,dist+10001,-1);
    dist[s] = 0;
    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();
      for(int i = 0; i < 4; i++){
        for(int j = 0; j < 10; j++){
          if(i == 3 && j == 0) continue;
          vector<int> nxt_digits = num2vec(cur);
          nxt_digits[i] = j;
          int nxt = vec2num(nxt_digits);
          if(!sieve[nxt] || dist[nxt] != -1) continue;
          dist[nxt] = dist[cur] + 1;
          Q.push(nxt);
        }
      }
    }
    if(dist[e] == -1) cout << "Impossible\n";
    else cout << dist[e] << '\n';
  }  
}
