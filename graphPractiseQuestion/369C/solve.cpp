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

void dfs(int node,vi &mark , vector<int> adj[], vi vis, vi count){
    vis[node] =1 ;
    count[node] = mark[node];
    for(auto adjnodes : adj[node]){
        if(!vis[adjnodes]){
            dfs(adjnodes, mark, adj, vis, count);
            count[node] += count[adjnodes];
        }
    }

}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // t = 1;
    // cin >> t;
    while (t--)
    {
        int n;cin >> n;
        vector<int> adj[n];
        vi mark(n, 0);
        for(int i = 0; i< n-1; i++){
            int u, v, r;
            cin >> u >> v >> r;
            if(r == 2){
                mark[v-1] = 1;
                mark[u-1] = 1;
            }
            adj[--u].push_back(--v);
        }
        for(int i = 0; i< n; i++){
            deb(mark[i]);
        }
        int ans = 0;
        vi vis(n, 0);
        vi count(n, 0);
        dfs(0, mark, adj, vis, count);
        for(int i = 0; i< n; i++){
            if(count[i] == 1){
                ans++;
            }
        }
        for(int i = 0; i< n; i++){
            deb(vis[i]);
        }
        cout << ans << endl;

    }
    return 0;
}