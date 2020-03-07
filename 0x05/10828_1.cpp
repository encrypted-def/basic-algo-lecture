#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  while(n--){ // n번 반복
    string c;
    cin >> c;
    if(c=="push"){
      int t;
      cin >> t;
      S.push(t);
    }
    else if(c=="pop"){
      if(S.empty()) cout << -1 << '\n';
      else{
        cout << S.top() << '\n';
        S.pop();
      }
    }
    else if(c=="size")
      cout << S.size() << '\n';
    else if(c=="empty")
      cout << (int)S.empty() << '\n';
    else{ // top
      if(S.empty()) cout << -1 << '\n';
      else cout << S.top() << '\n';
    }
  }
}
