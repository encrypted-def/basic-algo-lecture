// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/0d764ae5be1740e5925b8d650eee7303
#include <bits/stdc++.h>
using namespace std;

int N, s, e, i;
int q[2000005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while(N--){
    string com;
    cin >> com;
    if(com == "push"){
      cin >> q[e++];
    } else if(com == "pop"){
      cout << (s == e ? -1 : q[s++]) << '\n';
    } else if(com == "size"){
      cout << e - s << '\n';
    } else if(com == "empty"){
      cout << (s == e) << '\n';
    } else if(com == "front"){
      cout << (s == e ? -1 : q[s]) << '\n';
    } else if(com == "back"){
      cout << (s == e ? -1 : q[e-1]) << '\n';
    }
  }
}
