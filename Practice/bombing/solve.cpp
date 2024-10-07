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
        int n;
        cin >> n;
        vi v(n);
        for (auto &k : v)
        {
            cin >> k;
        }
        sort(v.begin(), v.end());
        multiset<int> mt(v.begin(), v.end());
        int ans = INT_MIN;
        queue<pair<int, int>> q;
        fo(i, n)
        {
            multiset<int> temp = mt;
            int num = v[i];
            temp.erase(temp.find(num));
            int count = 1;
            int range = 1;
            q.push({num, range});
            while (!q.empty())
            {
                int size = q.size();
                for (int k = 0; k < size; k++)
                {
                    auto top = q.front();
                    q.pop();
                    int point = top.first;
                    int var = top.second;
                    for (int j = point - var; j <= point + var; j++)
                    {
                        if (temp.find(j) != temp.end())
                        {
                            q.push({j, var + 1});
                            // deb({j,var+1})
                            // if (num == 5)
                            // {
                            //     deb(j);
                            //     deb(var + 1);
                            // }
                            temp.erase(temp.find(j));
                            count++;
                        }
                    }
                }
            }
            ans = max(ans, count);
        }
        cout << ans << endl;
    }
    return 0;
}