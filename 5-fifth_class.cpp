//https://codeforces.com/group/roU9OApnmM/contest/609335


// A - Dice Combinations - CSES (Made by Teacher)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<bool> vb;

#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define esta(x, c) ((c).find(x) != (c).end())

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "====================" << endl
#define DBGV(v) forn(_, SZ(v)) cerr << v[_] << " "; cerr << endl

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const ll MAXN = 250 * 501;

//Bottom Up
/*
int main() {
    FIO;
    ll n; cin >> n;
    vl dp(n+1, 0);
    dp[0] = 1;

    forn(i, n+1) {
        forr(x, 1, 7) {
            if (i - x >= 0)
                dp[i] = (dp[i] + dp[i - x]) % MOD;
        }
    }

    cout << dp[n];
    return 0;
}

*/

//Top down
void solvedp(ll n, vl &dp, vector<bool> &visto) {
    forr(x, 1, 7) {
        if (n - x >= 0) {
            if (!visto[n - x])
                solvedp(n - x, dp, visto);
            dp[n] = (dp[n] + dp[n - x]) % MOD;
        }
    }
    visto[n] = true;
    return;
}

int main() {
    FIO;
    ll n; cin >> n;
    vl dp(n + 1, 0);
    vector<bool> visto(n + 1, false);
    dp[0] = 1;
    visto[0] = true;

    solvedp(n, dp, visto);
    cout << dp[n] << endl;

    return 0;
}





// B- Minimizing Coins - CSES

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<bool> vb;

#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define esta(x, c) ((c).find(x) != (c).end())

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "====================" << endl
#define DBGV(v) forn(_, SZ(v)) cerr << v[_] << " "; cerr << endl

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const ll MAXN = 250 * 501;



int main() {
    FIO;

    ll n, x;
    cin >> n >> x;

    vl moneda(n);
    for (ll i = 0; i < n; i++)
        cin >> moneda[i];

    vl dp(x + 1, INF);
    dp[0] = 0;

    for (ll i = 1; i <= x; i++) {
        for (ll j = 0; j < n; j++) {
            if (moneda[j] <= i && dp[i - moneda[j]] + 1 < dp[i])
                dp[i] = dp[i - moneda[j]] + 1;
        }
    }
    if (dp[x] >= INF)
        cout << -1 << "\n";
    else
        cout << dp[x] << "\n";

    return 0;
}



// C - Coin Combinations I - CSES

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<bool> vb;

#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define esta(x, c) ((c).find(x) != (c).end())

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "====================" << endl
#define DBGV(v) forn(_, SZ(v)) cerr << v[_] << " "; cerr << endl

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const ll MAXN = 250 * 501;





int main() {
    FIO;
    ll n, x;
    cin >> n >> x;

    vl moneda(n);
    forn(i, n) cin >> moneda[i];

    vl dp(x + 1, 0);
    dp[0] = 1;

    forr(i, 1, x + 1) {
        forn(j, n) {
            if (i - moneda[j] >= 0) {
                dp[i] = (dp[i] + dp[i - moneda[j]]) % MOD;
            }
        }
    }

    cout << dp[x] << '\n';
    return 0;
}



// D - Coin Combinations II - CSES

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<bool> vb;

#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define esta(x, c) ((c).find(x) != (c).end())


const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const ll MAXN = 250 * 501;



int main() {
    FIO;
    ll n, x;
    cin >> n >> x;

    vl moneda(n);
    forn(i, n) cin >> moneda[i];

    vl dp(x + 1, 0);
    dp[0] = 1;


    forn(j, n) {
        ll c = moneda[j];
        forr(i, c, x + 1) {
            dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }

    cout << dp[x] << '\n';
    return 0;
}



// E - Increasing Subsequence - CSES

//By Monazo (Teacher)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
#define dbgv(v) for (int u : v) cerr << u << " "; cerr << endl

int LIS(vector<int> &v, int n) {
    vector<int> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++) {
        // dbgv(ans);
        if (v[i] > ans.back()) {
            ans.push_back(v[i]);
        } else {
            int pos = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
            ans[pos] = v[i];
        }
    }
    return int(ans.size());
}

int main() {
    FIN;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << LIS(v, n) << "\n";

    return 0;
}



// F - Longest Common Subsequence - CSES

//By Monazo (Teacher)
#include <bits/stdc++.h>

using namespace std;

#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
#define pb push_back

int main() {
    FIN;

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    vector<vector<pair<int,int>>> prev(n + 1, vector<pair<int,int>>(m + 1));
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i - 1 >= 0 && dp[i-1][j] > dp[i][j]) {
                dp[i][j] = dp[i-1][j];
                prev[i][j] = {i-1, j};
            }
            if (j - 1 >= 0 && dp[i][j-1] > dp[i][j]) {
                dp[i][j] = dp[i][j-1];
                prev[i][j] = {i, j-1};
            }
            if (i - 1 >= 0 && j - 1 >= 0 && a[i-1] == b[j-1]
                && dp[i-1][j-1] + 1 > dp[i][j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                prev[i][j] = {i-1, j-1};
            }
        }
    }

    cout << dp[n][m] << "\n";
    pair<int,int> cur = {n, m};
    vector<int> ans;

    while (cur != make_pair(0, 0)) {
        pair<int,int> next = prev[cur.first][cur.second];
        int delta = (cur.first - next.first) + (cur.second - next.second);
        if (delta == 2) {
            ans.pb(a[next.first]);
        }
        cur = next;
    }

    reverse(ans.begin(), ans.end());
    for (int u : ans) cout << u << " ";
    cout << "\n";

    return 0;
}




// G - Knapsack Problem



//By Monazo (Teacher)
 
#include <bits/stdc++.h>

using namespace std;

#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)

int main() {
    FIN;

    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, -1);
    dp[0] = 0;

    vector<int> p(n), v(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        vector<int> next = dp;
        for (int j = 0; j <= x; j++) {
            if (j - p[i] >= 0 && dp[j - p[i]] != -1) {
                next[j] = max(next[j], dp[j - p[i]] + v[i]);
            }
        }
        dp = next;
        // for(int u : dp) cerr << u << " "; cerr << endl;
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}
