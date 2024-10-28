// n < = 10 to the power 6
// let x be a number now , how many 1 <= y <= n exist such that gcd(x,y) = 1.

// and let x be one of the queries and let q <= 10 to the power 6.

// let x = P1^1 * P2^2 * ... Pk ^k.

// so for gcd(x,y ) = 1, means that y is not divisible by any of the Pis.

// x <= 10^6  means atmost 7 prime factors.


// y i snot divisible by Pis, so
// the amount of numbers divisible by P1 is floor(n/P1).

// y can be = n - n/P1 - n/P2 ... n/Pk but what if your number is divisible by P1 and P2 now you are subtracting it again.
// we will add n/(P1 * P2) + n/(P1*P3) + n/(P1 * Pk)

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
        
    }
    return 0;
}