#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
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
        int n, k; cin >> n >> k;
        int i;
        vi v;
        fo(i,n){
            int num ; cin >> num;
            v.pb(num);
        }

        sort(all(v));

        int start = v[0];
        int end = v[0];
        int ans =  0;
        for(int i = 0; i < n-1; i++){
            if(v[i+1] - v[i] <= k){
                end = v[i+1];
            }
            else{
                ans += end - start + 1 + k;
                start = v[i+1];
                end = v[i+1];
            }
        }
        ans += (end - start + k + 1);
        cout << ans ;
        
    }
    return 0;
}