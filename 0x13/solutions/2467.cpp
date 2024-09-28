// Authored by : kimhs1470
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/3da517caaaf044dbbc3b2a2c8cc40380
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    ll ans1 = 1e9+1, ans2 = 1e9+1;
    ll mn = ans1 + ans2;
    /* i번째 용액을 선택하고 합쳤을때 가장 0에 근접한 용액을 이분탐색으로 선택 */
    for(int i = 0; i < n-1; i++){
        int st = i + 1;
        int en = n - 1;
        
        while (st <= en) {
            int mid = st + (en - st) / 2;
            ll sum = a[i] + a[mid];
            
            if(abs(sum) < abs(mn)) {
              mn = sum;
              ans1 = a[i];
              ans2 = a[mid];
            }

            if(sum < 0) st = mid + 1;
            else if(sum > 0) en = mid - 1;
            else {
              /* sum이 0이면 더이상 탐색할 필요X. */
              cout << ans1 << " " << ans2 << endl;
              return 0;
            }
        }
    }

    cout << ans1 << " " << ans2;
}