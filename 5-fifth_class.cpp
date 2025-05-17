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




// C - Coin Combinations I - CSES




// D - Coin Combinations II - CSES




// E- Increasing Subsequence - CSES





// F- Longest Common Subsequence - CSES
