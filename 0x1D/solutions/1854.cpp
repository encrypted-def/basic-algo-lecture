// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : Baejinho4028
// https://www.acmicpc.net/problem/1854
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int,int>> adj[1002];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue<int> d[1002];
    d[1].push(0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({d[1].top(), 1});

    while (!pq.empty()) {
        auto [cw, cv] = pq.top(); pq.pop();

        for (auto [nw, nv] : adj[cv]) {
            if (d[nv].size() < k) {
                d[nv].push(cw + nw);
                pq.push({cw + nw, nv});
            } 
            else if (d[nv].top() > cw + nw) {
                d[nv].pop();
                d[nv].push(cw + nw);
                pq.push({cw + nw, nv});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << (d[i].size() < k ? -1 : d[i].top()) << '\n';
    }
}

/**
 * 각 도시마다 걸리는 거리를 내림차순 힙으로 관리합니다.
 * 해당 도시까지의 상위 k개의 거리까지만을 저장하여, d[i].top()으로 k번째 최단거리를 추출함으로써 문제를 해결합니다.
 * 만약 거리의 개수가 k개 이하라면 -1을 출력합니다.
 */
