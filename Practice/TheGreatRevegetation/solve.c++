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
    // cin >> t;
    t = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n);
        fo(i, k)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        // fo(i,n){
        //     fo(j,n){
        //         deb(adj[i][j]);
        //     }
        // }
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int k = 1; k <= 4; k++)
            {
                bool works = true;
                for (int j : adj[i])
                {
                    if (ans[j] == k)
                        works = false;
                }

                if (works)
                {
                    ans[i] = k;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i];
        }
    }
    return 0;
}