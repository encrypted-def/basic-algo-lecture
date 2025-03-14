// Authored by : keyboardmunji
// Co-authored by : -
// http://boj.kr/e0c5f4a5d5fc4c8bae9107590e538eae
#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int n, m, cnt, en, ans = 0x7f7f7f7f;
int chk[1005]; // 각 팀이 구간속에 모두 있는지 확인하는 벡터
vector<pair<int, int>> a; // 능력치와 각팀의 인덱스를 저장하는 벡터

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int num;
            cin >> num;
            a.push_back({ num, i });
        }
    }
    sort(a.begin(), a.end());

    for (int st = 0;st < n * m;st++) {
        // 구간 속에 각 팀이 모두 포함되게 en을 증가
        while (cnt < n && en < n * m) {
            if (chk[a[en].Y] == 0)
                cnt++;
            chk[a[en].Y]++;
            en++;
        }
        if (cnt != n)
            break;
        ans = min(ans, a[en - 1].X - a[st].X);
        chk[a[st].Y]--;
        if (chk[a[st].Y] == 0)
            cnt--;
    }
    cout << ans;
    return 0;
}