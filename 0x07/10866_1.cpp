// http://boj.kr/82805c43b7ff48adb21a37403d55f736
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> DQ;
  int n;
  cin >> n;
  while (n--) {
    string q;
    cin >> q;
    if (q == "push_back") {
      int val;
      cin >> val;
      DQ.push_back(val);
    }
    else if (q == "push_front") {
      int val;
      cin >> val;
      DQ.push_front(val);
    }
    else if(q == "pop_front"){
      if(DQ.empty()) cout << -1 << '\n';
      else{
        cout << DQ.front() << '\n';
        DQ.pop_front();
      }
    }
    else if(q == "pop_back"){
      if(DQ.empty()) cout << -1 << '\n';
      else{
        cout << DQ.back() << '\n';
        DQ.pop_back();
      }
    }
    else if (q == "size")
      cout << DQ.size() << '\n';
    else if (q == "empty")
      cout << DQ.empty() << '\n';
    else if (q == "front") {
      if(DQ.empty()) cout << -1 << '\n';
      else cout << DQ.front() << '\n';
    }
    else { // back
      if(DQ.empty()) cout << -1 << '\n';
      else cout << DQ.back() << '\n';
    }
  }
}
