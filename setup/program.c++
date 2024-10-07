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
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
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
    // t = 1;
    while (t--)
    {
      ll n , k;
      cin >> n >> k;
      vector<ll> v;
      set<ll> gcds;
      ll gcdddd = -1;
      bool onesided = true;
      for(int i = 0; i< n; i++){
        // cin >> v[i];
        int num; cin >> num;
        if(num == k){
            if( i != 0 or i != n-1){
                onesided = false;
            }
            continue;
        }
        v.push_back(num);
        // deb(v[i]);
        if(gcdddd == -1){
            gcdddd = num;
        }
        else{
            gcdddd = gcd(gcdddd, num);
            gcds.insert(gcdddd);
        }
      }
        n = v.size();
      sort(v.begin(), v.end());
      if(n == 1){
        if(k == v[0]){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
      }
      else if ( gcds.size() == 1){
            if(onesided){
                cout << 1;
            }
      }
      else if (k == 1){
        cout << 1 << endl;
      }
      else if(v[0] == v[n-1]){
        if(k == v[0]){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
      }
      else if(gcds.size() == 1){
        cout << 1 << endl;
      }
      
      else{
        cout << 2 << endl;
      }
      


    }
    return 0;
}