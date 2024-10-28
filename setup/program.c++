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

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if (x.first != y.first)
        return x.first < y.first;
    else
        return x.second < y.second;
}
bool solve(ll mid, vl v ){
    int n = v.size();
    if(v.size()%2 == 0){
        int count = 0;
        for(int i = 0 ; i< n; i+=2){
            ll diff = v[i+1] - v[i];
            if(diff > mid)count++;
        }
        return count == 0;
    }
    else{
        // leaving the first index
        vl newv;
        for(int i = 1 ; i< n; i++){
            ll diff = v[i] - v[i-1];
            newv.push_back(diff);
        }
        sort(all(newv));
        int size = newv.size();
        // deb(size);
        ll secondLast = newv[size - 2];
        // deb(secondLast);
        if(secondLast > mid){
            return false;
        }
        return true;
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

    int t;
    cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        vl v(n);
        for(auto &i : v){
            cin >> i;
        }
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 2){
            cout << v[1] - v[0] << endl;
            continue;
        }
        ll ans = 0;
        ll left = 0;
        ll right = 1e18;
        while( left < right){
            ll mid = (left + right)/2;
            if(solve(mid, v)){
                ans = mid;
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
        cout << ans << endl;
        
    }

    return 0;
}
