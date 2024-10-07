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
const ll SEED=chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);
const ll INF = 0xFFFFFFFFFFFFFFFLL;

inline ll rnd(ll l=0,ll r = INF)
{return uniform_int_distribution<ll>(l,r)(rng);}
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
        int n;
        cin >> n;
        vpl v(n);
        for (auto &x : v)
        {
            cin >> x.first >> x.second;
        }

        ll ans = n;
        auto chk = [&](const ll i, const ll j) -> void
        {
            ll count = 0;
            ll x1 = v[i].first, y1 = v[i].second;
            ll x2 = v[j].first, y2 = v[j].second;

            for (auto &z : v)
            {
                ll x3 = z.first, y3 = z.second;
                ll area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
                if (area)
                {
                    count++;
                }
            }
            ans = min(ans, count);
        };

        if (n <= 20)
        {
            for (ll i = 0; i < n; i++)
                for (ll j = 0; j < i; j++)
                    chk(i, j);
        }
        else
        {
            for (ll itr = 0; itr < 2000; itr++)
            {
                ll u = 0, v = 0;
                while (u == v)
                {
                    u = rnd(0, n - 1);
                    v = rnd(0, n - 1);
                }
                chk(u, v);
            }
        }
        cout << ans << endl;
    }
    return 0;
}