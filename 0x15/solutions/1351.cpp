// Authored by : HJPark
// Co-authored by : -
// http://boj.kr/77e7bc44e10f4842972aba6421a07ec4
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, p, q;
unordered_map<ll, ll> dp;

ll dfs(ll x) {
    if (dp.find(x) != dp.end()) return dp[x];
    dp[x] = dfs(x / p) + dfs(x / q);
    return dp[x];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> q;
    dp[0] = 1;

    cout << dfs(n);
}

/*
피보나치 수열의 메모리제이션 방법과 유사합니다.
A_i의 값을 이전에 dp에 저장했다면 dp에 저장된 값을 반환합니다.
A_i의 값을 구한 적이 없으면 dfs를 통해서 구한 뒤에 dp에 저장합니다.
*/
