// Authored by : HJPark
// Co-authored by : -
// http://boj.kr/4e40a01c60d34310b91663881718bd77
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int ret[1000005];
int ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    ret[0] = a[0];

    for (int i = 0; i < n; i++) {
        if (ret[ans] < a[i]) {
            ret[ans + 1] = a[i];
            ans++;
        }
        else {
            int idx = lower_bound(ret, ret + ans, a[i]) - ret;
            ret[idx] = a[i];
        }
    }

    cout << ans + 1;
}
