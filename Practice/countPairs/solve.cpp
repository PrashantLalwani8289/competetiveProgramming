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
ll gcd(ll a, ll b)
{
  while (b != 0)
  {
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
  while (t--)
  {
    int n , k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi cnt(26, 0);
    for (char ch : s){
      cnt[ch - 'a']++;
    }
    for(int i = 0; i < 26; i++){
      char ch = 'a' + i;
      int count = cnt[i];
      if(count > 0){
        deb(ch);
        deb(count);
      }
    }
    int cntPairs = 0, cntOdd = 0;
    for(int c : cnt){
      cntPairs += c / 2;
      deb(cntPairs);
      cntOdd += c % 2;
      deb(cntOdd);
    }
    int ans = 2 * (cntPairs / k);
    deb(ans);
    cntOdd += 2 * (cntPairs % k);
    deb(cntOdd);
    if (cntOdd >= k) {
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}