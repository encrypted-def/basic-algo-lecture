// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/0aaffc76df1f4dd4872b53a3f1b3b277
#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--){
    string a;
   cin >> a;
   stack <int> S;

   for (auto c: a){
     if (!S.empty()){
       if (S.top() == 'A' && c == 'A') S.pop();
       else if (S.top() == 'B' && c == 'B') S.pop();
        else S.push(c);
      }
      else S.push(c);
   }
   if (S.empty()) ans++;
  }

  cout << ans << "\n";
}