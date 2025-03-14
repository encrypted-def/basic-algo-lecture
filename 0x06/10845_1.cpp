// http://boj.kr/702a66643c6245f6bc05cd760490c785
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  queue<int> Q;
  int n;
  cin >> n;
  while(n--){
    string q;
    cin >> q;
    if(q=="push"){
      int val;
      cin >> val;
      Q.push(val);
    }
    else if(q=="pop"){
      if(Q.empty()) cout << -1 << '\n';
      else{
        cout << Q.front() << '\n';
        Q.pop();
      }
    }
    else if(q=="size"){
      cout << Q.size() << '\n';
    }
    else if(q=="empty"){
      cout << Q.empty() << '\n';
    }    
    else if(q=="front"){
      if(Q.empty()) cout << -1 << '\n';
      else cout << Q.front() << '\n';
    }
    else{ // back
      if(Q.empty()) cout << -1 << '\n';
      else cout << Q.back() << '\n';
    }
  }
}
