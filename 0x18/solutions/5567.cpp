// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : connieya
// http://boj.kr/b55401d3ea7443158a824ac264a64a94
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<int> s;
    vector<int> graph[501];
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int f : graph[1]) { // 상근이의 친구
        s.insert(f);
        for (int ff: graph[f]) { // 상근이의 친구의 친구
            s.insert(ff);
        }
    }
    s.erase(1); // 상근이는 제외
    cout << s.size();
}