// Authored by : BueVonHun
// Co-authored by : -
// http://boj.kr/0087e15edd424497b1c8184f07dc4533
#include <bits/stdc++.h>
using namespace std;

const int kappa = 101;
int nx[6] = {0, 0, 1, -1, kappa, -kappa};
int ny[6] = {1, -1, 0, 0, 0, 0};

int Board[10100][100];
int Board2[10100][100];
bool vis[10100][100];
int dist[10100][100];
using namespace std;

void bfs(pair<int, int> start) {
    queue<pair<int, int>> que;
    vis[start.first][start.second]=true;
    dist[start.first][start.second]=0;
    que.push(start);
    while (!que.empty()) {
        pair<int, int> cur = que.front();que.pop();
        for (int i = 0; i < 6; i++) {
            int nxtX = cur.first+nx[i];
            int nxtY = cur.second+ny[i];
            if (nxtX<0 || nxtX >= 10100) continue;
            if (nxtY<0 || nxtY >= 100) continue;
            if (vis[nxtX][nxtY]) {
                if (Board[nxtX][nxtY]==0) {
                    if (dist[nxtX][nxtY] > dist[cur.first][cur.second]+1) {
                        Board2[nxtX][nxtY]=1;
                        dist[nxtX][nxtY] = dist[cur.first][cur.second]+1;
                        que.push({nxtX, nxtY});
                    }
                }
            }
            else {
                if (Board[nxtX][nxtY]==0) {
                    vis[nxtX][nxtY]=true;
                    Board2[nxtX][nxtY]=1;
                    dist[nxtX][nxtY]=dist[cur.first][cur.second]+1;
                    que.push({nxtX, nxtY});
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m,n,h;
    cin >> m >> n >> h;
    vector<pair<int, int>> start;
    for (int i = 0; i < 10100; i++)
        for (int j = 0; j < 100; j++) {
            Board[i][j]=-1;
            Board2[i][j]=-1;
        }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int tmp;
                cin >> tmp;
                Board[j+i*kappa][k]=tmp;
                Board2[j+i*kappa][k]=tmp;
                if (tmp==1)
                    start.push_back({j+i*kappa, k});
            }
        }
    }
    int ans = 0;
    bool f = true;
    for (auto cur:start) {
        if (!vis[cur.first][cur.second]) {
            bfs(cur);
        }
    }

    for (int i = 0; i < 10100; i++)
        for (int j = 0; j < 100; j++)
            if (Board2[i][j]==0) f = false;
    for (int i = 0; i < 10100; i++)
        for (int j = 0; j < 100; j++)
            ans=max(dist[i][j], ans);
    if (f) cout << ans << "\n";
    else cout << -1 << "\n";
    return 0;
}
