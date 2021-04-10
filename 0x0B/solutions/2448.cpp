// Authored by : unluckyjung
// Co-authored by : -
// http://boj.kr/31ef7320280b435db96205563d936931

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1024 * 3 + 2;

int n;
char board[MAX][MAX * 2 - 1];

void print_ans() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n * 2 - 1; ++ii) {
            if (board[i][ii] == '*') cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }
}

void fill_star(const int& x, const int& y) {
    board[x][y] = '*';
    board[x + 1][y - 1] = '*', board[x + 1][y + 1] = '*';

    for (int i = y - 2; i <= y + 2; ++i) {
        board[x + 2][i] = '*';
    }
}

void func(const int& s, const int& x, const int& y) {
    if (s == 3) {
        fill_star(x, y);
        return;
    }

    int ns = s / 2;
    func(ns, x, y);
    func(ns, x + ns, y - ns);
    func(ns, x + ns, y + ns);
}

void solve() {
    func(n, 0, n - 1);
    print_ans();
}

void input() {
    cin >> n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    input();
    solve();

    return 0;
}