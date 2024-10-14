#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n , x;
        cin >> n , x;
        int moves = 0;
        vi a(n);
        for(auto &i: a){
            cin >> i;
        }
        int left = *max_element(all(a));
        int right = 1e9;
        int ans = right;
        int sum = accumulate(all(a),0);
        auto ok = [&](int X){
            return ((sum + X -1)/ X) <= x;
        }
        while(left <= right){
        
            int mid = (left + right)/2;
            if(ok(mid)) ans = mid, right = mid-1;
            else left  = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}