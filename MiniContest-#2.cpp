// https://codeforces.com/group/roU9OApnmM/contest/610742
//Unlp Problems: SalvaKaraka, mateoiba30, Igna-s


//Our Solutions 




// A - Analysing Electrocardiograms


#include <bits/stdc++.h>
using namespace std;

bool esSano(const string& patron, const string& test) {
    int pLen = patron.size();
    int tLen = test.size();
    if (tLen % pLen != 0) return false;

    for (int i = 0; i < tLen; i++) {
        if (test[i] != patron[i % pLen]) {
            return false;
        }
    }
    return true;
}

int main() {
    string S;
    int N;
    cin >> S >> N;

    for (int i = 0; i < N; i++) {
        string P;
        cin >> P;
        if (esSano(S, P)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}




//B - Buying Paint

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<vector<int>> matriz;

vector<int> generar_espiral(vector<vector<int>> &mat, bool sentido_horario) {
    vector<int> espiral;
    vector<vector<bool>> visitado(n, vector<bool>(n, false));

    //derecha, abajo, izquierda, arriba
    vector<pair<int, int>> direcciones = sentido_horario ?
        vector<pair<int, int>>{{0,1},{1,0},{0,-1},{-1,0}} :
        vector<pair<int, int>>{{1,0},{0,1},{-1,0},{0,-1}};

    int i = 0, j = 0, direccion = 0;
    for (int k = 0; k < n * n; ++k) {
        espiral.push_back(mat[i][j]);
        visitado[i][j] = true;
        int ni = i + direcciones[direccion].first;
        int nj = j + direcciones[direccion].second;
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && !visitado[ni][nj]) {
            i = ni;
            j = nj;
        } else {
            direccion = (direccion + 1) % 4;
            i += direcciones[direccion].first;
            j += direcciones[direccion].second;
        }
    }
    return espiral;
}

vector<vector<int>> rotar_90(vector<vector<int>> mat) {
    vector<vector<int>> rotada(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            rotada[j][n - 1 - i] = mat[i][j];
    return rotada;
}

ll kadane(vector<int> &v) {
    ll max_actual = v[0], max_total = v[0];
    for (int i = 1; i < v.size(); ++i) {
        max_actual = max((ll)v[i], max_actual + v[i]);
        max_total = max(max_total, max_actual);
    }
    return max_total;
}

int main() {


    cin >> n;
    matriz.assign(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matriz[i][j];

    ll mejor_belleza = 0;

    vector<vector<int>> actual = matriz;
    for (int rot = 0; rot < 4; ++rot) {
        vector<int> espiral_horaria = generar_espiral(actual, true);
        vector<int> espiral_antihoraria = generar_espiral(actual, false);
        mejor_belleza = max(mejor_belleza, kadane(espiral_horaria));
        mejor_belleza = max(mejor_belleza, kadane(espiral_antihoraria));
        actual = rotar_90(actual);
    }

    cout << mejor_belleza << '\n';
    return 0;
}


// E - Elisas Boxes



#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int result = -1;
    int box;

    for (int i = 0; i < N; ++i) {
        cin >> box;
        if (box >= M) {
            result = i + 1;
            break;
        }
    }

    cout << result << '\n';
    return 0;
}



//I - ICPC Challenge	


#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0);


const int MAXN = 1e5 + 5;
vector<bool> visto(MAXN, false);



void dfs(int v, vector<vector<int>> &g, vector<long long> &soborno, long long &valor, long long &cont) {
    if (soborno[v]==valor) cont++;
    visto[v] = true;
    for (auto u : g[v]) {
        if (!visto[u]) {
            dfs(u, g, soborno, valor, cont);
        }
    }
}


int p;

int main() {
    FIN;
    int x, q;
    cin >> x >> q;
    vector<long long> soborno(x);
    for (int i = 0; i < x; i++) {
        cin >> soborno[i];
    }

    vector<vector<int>> g(x);
    for (int i = 0; i <-1+ x; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);

    }


    while (q--){
    int n;
    cin >>n;
    long long valor;
    cin >>valor;

    long long cont = 0;
    fill(visto.begin(), visto.end() , false);
    dfs(n-1, g, soborno, valor, cont);

    cout << cont << "\n";
    }
    return 0;
}




//Wrongs



// D - Delivering Orders (Time limit exceeded on test 4)

#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {
    // FIN;
    
    int k, n;
    cin >> k;
    vector<long long> stock(k);  // usar long long p
    for (int i = 0; i < k; i++) {
        cin >> stock[i];
    }

    cin >> n;
    vector<vector<long long>> pedidos(n, vector<long long>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> pedidos[i][j];
        }
    }

    int dia = 1;
    while (true) {
        for (int i = 0; i < n; i++) {
            bool puede = true;
            for (int j = 0; j < k; j++) {
                if (stock[j] < pedidos[i][j]) {
                    cout << dia << " " << i + 1 << "\n";
                    return 0;
                }
            }
            for (int j = 0; j < k; j++) {
                stock[j] -= pedidos[i][j];
            }
        }
        dia++;
    }

    return 0;
}






// F - First Problem  (Time limit exceeded on test 36)



#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0);

int main() {
   FIN;
   char codOp;
   int a, b;
   int n, querys;
   cin >> n;
   cin >> querys;

   vector<int> vec(n+1);

   for (int i=1;i<n+1;i++){
    cin>>vec[i];

   }

   for (int i=0;i<querys;i++){
       cin >> codOp;
       cin >> a;
       cin >> b;


       if (codOp == 'Q'){
            int maxi =-1;
            for (int j=a;j<=b;j++){
                maxi = max(maxi,vec[j]);
            }
            cout << maxi <<endl;


       }
       else if (codOp == 'A'){

            for (int j=a;j<=b;j++){
                vec[j]=vec[j] +1;
            }

       }
       else if (codOp == 'R'){

            int maxi =-1;
            for (int j=1;j<n+1;j++){
                maxi = max(maxi,vec[j]);
            }
            for (int j=a;j<=b;j++){
                if (vec[j] == maxi)
                    vec[j]=0;
            }

       }

   }

    return 0;
}




//  K - Killable Demon (Wrong answer on test 2)


#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0);


const int MAXN = 1e5 + 5;
vector<bool> visto(MAXN, false);

int dfs(int v,vector<vector<int>> &dep, vector<vector<int>> &g, vector<long long> &soborno, long long &maxi, long long suma) {


    visto[v] = true;
    if (dep[v].empty()) return soborno[v];

    int aux=0;
    for (auto u : g[v]) {
        if (!visto[u]) {
           aux += dfs(u,dep, g, soborno, maxi, suma );

        }
    }
    if (aux>maxi) maxi=aux;


    return aux;



}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> soborno(n);
    for (int i = 0; i < n; i++) {
        cin >> soborno[i];
    }

    vector<vector<int>> g(n);
    vector<vector<int>> dep(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[b].push_back(a);
        dep[a].push_back(b);
    }

    long long cont = 0;
    for (int i = 0; i < n; i++) {


    if (dep[i].empty()){
        if (!visto[i]) {
            long long maxi = 0;
            int aux =dfs(i,dep, g, soborno, maxi, 0);

            if (aux>0)
            cont += aux;
        }
    }
}
    cout << cont -1 << "\n";
    return 0;
}







//Teacher solutions (Monazo)


// (A) Analysing Electrocardiograms


#include <bits/stdc++.h>

using namespace std;

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main() {
	FIN;
	string s;
	cin >> s;
	int tam = int(s.size());
	int n; cin >> n;
	for(int _ = 0; _ < n; _++) {
		string t; cin >> t;
		bool ans = true;
		for(int i = 0; i < t.size(); i++) {
			if(t[i] != s[i%tam]) ans = false;
		}
		int tam2 = int(t.size());
		if(tam2 % tam != 0) ans = false;
		if(ans) cout << "Yes\n";
		else cout << "No\n";
	}
	
	
	return 0;
}



// (B) Buying Paint


#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
 
const int INF = 1e9+7;
 
vector <pair<int,int>> moves = {{-1,0},{0,1},{1,0},{0,-1}};
 
bool valid(int x, int y, int n, vector<vector<int>> &v) {
	if(x < 0 or x >= n) return false;
	if(y < 0 or y >= n) return false;
	if(v[x][y] == INF) return false;
	return true;
}
 
ll getSpiral(vector<vector<int>> &v, int n, int x, int y, ll sum = 0, int move = 0) {
	sum += v[x][y];
	v[x][y] = INF;
	if(sum < 0) sum = 0;
	ll ans = 0;
	int newx = x + moves[move].first;
	int newy = y + moves[move].second;
	int cont = 0;
	while(!valid(newx,newy,n,v) and cont < 4) {
		cont++;
		move++;
		move %= 4;
		newx = x + moves[move].first;
		newy = y + moves[move].second;
	}
	if(cont == 4) return sum;
	return max(sum,getSpiral(v,n,newx,newy,sum,move));
}
 
int main() {
	FIN;
	
	int n; cin >> n;
	vector <vector<int>> v(n,vector<int>(n));
	forn(i,n) {
		forn(j,n) {
			cin >> v[i][j];
		}
	}
	ll ans = 0;
	vector<vector<int>> copia = v;
	ans = max(ans,getSpiral(copia,n,0,0));
	copia = v;
	ans = max(ans,getSpiral(copia,n,0,n-1));
	copia = v;
	ans = max(ans,getSpiral(copia,n,n-1,n-1));
	copia = v;
	ans = max(ans,getSpiral(copia,n,n-1,0));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			swap(v[i][j],v[j][i]);
		}
	}
	
	copia = v;
	ans = max(ans,getSpiral(copia,n,0,0));
	copia = v;
	ans = max(ans,getSpiral(copia,n,0,n-1));
	copia = v;
	ans = max(ans,getSpiral(copia,n,n-1,n-1));
	copia = v;
	ans = max(ans,getSpiral(copia,n,n-1,0));
	
	
	
	cout << ans << "\n";
	return 0;
}


//(D) Delivering Orders

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main() {
	FIN;
	
	int k; cin >> k;
	vector <ll> a(k);
	for(int i = 0; i < k; i++) cin >> a[i];
	int n; cin >> n;
	vector <vector<ll>> v(n,vector<ll>(k));
	vector <ll> acum(k);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			cin >> v[i][j];
			acum[j] += v[i][j];
		}
	}
	
	ll r = 1e18;
	for(int i = 0; i < k; i++) {
		if(acum[i] != 0) r = min(r,a[i]/acum[i]+1);
		//~ cerr << (a[i]+acum[i]-1)/acum[i] << " ";
	} 
	
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			a[j] -= (r-1) * v[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			a[j] -= v[i][j];
			if(a[j] < 0) {
				cout << r << " " << i+1 << "\n";
				return 0;
			}
		}
	}
	
	return 0;
}


//(E) Elisas Boxes

#include <bits/stdc++.h>

using namespace std;

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)

int main() {
	FIN;
	
	int n, m;
	cin >> n >> m;
	vector <int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int pos = -1;
	for(int i = 0; i < n; i++) {
		if(v[i] >= m) {
			pos = i+1;
			break;
		}
	}
	
	cout << pos << "\n";
	
	return 0;
}


// (G) Generating Polygons

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()

typedef long double ld;

void solve_problem() {
	int n, A;
	cin >> n >> A;
	if(n - 2 > A * 2) {
		cout << "No\n";
		return;
	}
	vector <pair<int,int>> up, down;
	cout << "Yes\n";
	int x = 0;
	int cont = 0;
	while(n > 2) {
		n -= 2;
		//~ cout << x << " " << 0+cont%2 << "\n";
		//~ cout << x << " " << 1+cont%2 << "\n";
		down.pb({x,cont%2});
		up.pb({x,1+cont%2});
		cont++;
		x++;
	}
	A -= cont-1;
	if(n == 2) {
		down.pb({x+A-1,cont%2});
		up.pb({x+A-1,1+cont%2});
		//~ cout << x + A << " " << 0 << "\n";
		//~ cout << x + A << " " << 1 << "\n";
	} else {
		down.pb({x+2*A-1,cont%2});
	}
	for(int i = 0; i < down.size(); i++) {
		cout << down[i].first << " " << down[i].second << "\n";
	}
	reverse(all(up));
	for(int i = 0; i < up.size(); i++) {
		cout << up[i].first << " " << up[i].second << "\n";
	}
}

int main() {
	FIN;
	
	int t; cin >> t;
	while(t--) {
		solve_problem();
	}
	
	return 0;
}


//(H) Huron Designs


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()

typedef long double ld;

struct task {
	ll d, p, c, lx, rx, ly, ry;
};

bool bit(int i, int mask) {
	return mask&(1<<i);
}

int main() {
	FIN;
	
	int n; cin >> n;
	vector <task> v(n);
	forn(i,n) {
		cin >> v[i].d >> v[i].p >> v[i].c >> v[i].lx >> v[i].rx >> v[i].ly >> v[i].ry;
	}
	vector <ld> dp(1<<n,0);
	ld ans = 0.0;
	for(int mask = 1; mask < (1<<n); mask++) {
		vector <int> todos;
		ll cTotal = 0;
		forn(i,n) {
			if(bit(i,mask)) {
				todos.pb(i);
				cTotal += v[i].c;
			}
		}
		for(int i : todos) {
			// ultimo que hago es i
			// suma p si cTotal <= d
			// si cTotal <= ly (suma bonus)
			// si cTotal > ry (no suma bonus)
			// else suma (ry - cTotal) * bonus
			ld bonus = ((ld)v[i].lx + v[i].rx)/2;
			ld profit = (cTotal <= v[i].d) ? (ld)v[i].p : (ld)0;
			if(cTotal > v[i].d) continue;
			ld factorBonus = 0;
			if(cTotal <= v[i].ly) factorBonus = 1.0;
			else if(cTotal > v[i].ry) factorBonus = 0.0;
			else factorBonus = ((ld)v[i].ry-cTotal)/(v[i].ry-v[i].ly);
			dp[mask] = max(dp[mask],dp[mask^(1<<i)] + profit + bonus * factorBonus);
		}
		ans = max(ans,dp[mask]);
	}
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	
	
	return 0;
}

//(I) ICPC Challenge

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = 1e9+7;

void DFS(int cur, vector<vector<int>> &g, vector<int> &in, vector<int> &out, vector <int> &r, int p = -1) {
	in[cur] = r.size();
	r.pb(cur);
	for(int next : g[cur]) {
		if(next != p) DFS(next,g,in,out,r,cur);
	}
	out[cur] = r.size();
}

int main() {
	FIN;
	
	int n, q;
	cin >> n >> q;
	vector <int> v(n);
	map <int,vector<int>> mapa;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector <vector<int>> g(n);
	forn(i,n-1) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	vector <int> in(n), out(n), r;
	DFS(0,g,in,out,r);
	//~ forn(i,n) cerr << i << " "; cerr << endl;
	//~ for(int u : r) cerr << u << " "; cerr << endl;
	//~ for(int u : r) cerr << v[u] << " "; cerr << endl;
	
	forn(i,n) {
		mapa[v[r[i]]].pb(i);
	}
	
	forn(i,q) {
		int x, k;
		cin >> x >> k;
		x--;
		//~ cerr << in[x] << " " << out[x] << "\n";
		vector <int> &aux = mapa[k];
		cout << lower_bound(all(aux),out[x]) - lower_bound(all(aux),in[x]) << "\n";
	}
	
	
	return 0;
}


//(J) JuPaels Palindrome

#include <bits/stdc++.h>

using namespace std;

typedef int ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define esta(x,c) (c).find(x) != (c).end()
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()

int solve(vector <pair<int,int>> &p, vector <pair<int,int>> &s) {
	int pos = 0;
	int ans = 0;
	for(auto [h,id] : p) {
		while(pos < s.size() and s[pos].first <= h) {
			if(s[pos].first == h) {
				ans = max(ans,abs(s[pos].second-id));
			}
			pos++;
		}
	}
	return ans;
}

int main() {
	FIN;
	
	int n; cin >> n;
	string pal; cin >> pal;
	vector <int> v(n);
	forn(i,n) v[i] = pal[i]-'a';
	
	int hash = 0, hash_final = 0;
	vector <pair<int,int>> prefix;
	prefix.pb({0,-1});
	forn(i,n) {
		int u = v[i];
		hash = hash ^ (1<<u);
		prefix.pb({hash,i});
	}
	hash_final = hash;
	hash = 0;
	vector <pair<int,int>> suffix;
	suffix.pb({0,n});
	for(int i = n-1; i >= 0; i--) {
		int u = v[i];
		hash = hash ^ (1<<u);
		suffix.pb({hash,i});
	}
	
	sort(all(prefix));
	//~ sort(all(suffix));
	int ans = solve(prefix,prefix);
	forn(bit,26) {
		vector <pair<int,int>> l, r;
		for(auto [h,id] : prefix) {
			if(h & (1<<bit)) {
				r.pb({h^(1<<bit),id});
			} else {
				l.pb({h^(1<<bit),id});
			}
		}
		//~ for(auto [u,id] : l) cerr << u << " "; cerr << endl;
		//~ for(auto [u,id] : r) cerr << u << " "; cerr << endl;
		//~ cerr << solve(l,prefix) << endl;
		//~ cerr << "==================" << endl;
		ans = max(ans,solve(l,prefix));
		ans = max(ans,solve(r,prefix));
		
	}
	cout << ans << "\n";
	
	
	
	return 0;
}

