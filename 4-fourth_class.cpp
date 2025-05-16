//https://codeforces.com/group/roU9OApnmM/contest/522712

//A. King Escape

#include <bits/stdc++.h>
using namespace std;


int obtener_cuadricula(int fila, int columna, int reinaFila, int reinaColumna) {
    if (fila < reinaFila && columna < reinaColumna) return 1;
    if (fila < reinaFila && columna > reinaColumna) return 2;
    if (fila > reinaFila && columna < reinaColumna) return 3;
    if (fila > reinaFila && columna > reinaColumna) return 4;
    return 0;
}


bool cuadricula_valida(int reyFila, int reyColumna, int objetivoFila, int objetivoColumna, int reinaFila, int reinaColumna) {
    int cuadriculaRey = obtener_cuadricula(reyFila, reyColumna, reinaFila, reinaColumna);
    int cuadriculaObjetivo = obtener_cuadricula(objetivoFila, objetivoColumna, reinaFila, reinaColumna);
    return cuadriculaRey == cuadriculaObjetivo;
}

int main() {
    int tamanoTablero;
    cin >> tamanoTablero;

    int reinaFila, reinaColumna;
    cin >> reinaFila >> reinaColumna;

    int reyFila, reyColumna;
    cin >> reyFila >> reyColumna;

    int objetivoFila, objetivoColumna;
    cin >> objetivoFila >> objetivoColumna;

    if (cuadricula_valida(reyFila, reyColumna, objetivoFila, objetivoColumna, reinaFila, reinaColumna)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}





//It is suposed to practice Grafhs, so i´m uploading also the intended solution

//(Made by the teacher)
#include <bits/stdc++.h>
 
using namespace std;
 
bool is_in(int x,int y, int n) {
	return (x >= 0 and x < n and y >= 0 and y < n);
}
 
void DFS(int x, int y, vector<vector<bool>> &visto, int n) {
	visto[x][y] = true;
	for(int dx : {-1,0,1}) {
		for(int dy : {-1,0,1}) {
			if(is_in(x+dx,y+dy,n) and !visto[x+dx][y+dy]) {
				DFS(x+dx,y+dy,visto,n);
			}
		}
	}
}
 
int main() {
	int n; cin >> n;
	int ax, ay; cin >> ax >> ay; ax--; ay--;
	int bx, by; cin >> bx >> by; bx--; by--;
	int cx, cy; cin >> cx >> cy; cx--; cy--;
	
	vector<vector<bool>> visto(n,vector<bool>(n,false));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == ax) visto[i][j] = true;
			if(j == ay) visto[i][j] = true;
			if(ax-ay == i-j) visto[i][j] = true;
			if(ax+ay == i+j) visto[i][j] = true;
		}
	}
	
	DFS(bx,by,visto,n);
	
	if(visto[cx][cy]) cout << "YES\n";
	else cout << "NO\n";
		
	return 0;
}













//C - Rumor


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<bool> visto(MAXN, false);

void dfs(int v, vector<vector<int>> &g, vector<long long> &soborno, long long &maxi) {
    maxi = min(maxi, soborno[v]);
    visto[v] = true;
    for (auto u : g[v]) {
        if (!visto[u]) {
            dfs(u, g, soborno, maxi);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> soborno(n);
    for (int i = 0; i < n; i++) {
        cin >> soborno[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    long long cont = 0;
    for (int i = 0; i < n; i++) {
        if (!visto[i]) {
            long long maxi = soborno[i];
            dfs(i, g, soborno, maxi);
            cont += maxi;
        }
    }

    cout << cont << "\n";
    return 0;
}



//D - The Lakes


#include <bits/stdc++.h>
using namespace std;

long long bfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<int>> &a) {

    //Chequea si no se fue al carajo, si es 0 0 si ya pase
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || a[i][j] == 0)
        return 0;

    vis[i][j] = true;

    long long sum = a[i][j];
    sum += bfs(i - 1, j, n, m, vis, a);
    sum += bfs(i + 1, j, n, m, vis, a);
    sum += bfs(i, j - 1, n, m, vis, a);
    sum += bfs(i, j + 1, n, m, vis, a);
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        long long maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > 0 && !vis[i][j]) {
                    maxi = max(maxi, bfs(i, j, n, m, vis, a));
                }
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}



// E - Cyclic Components


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<bool> visto(MAXN, false);

void dfs(int v, vector<vector<int>> &g, bool &es_ciclo) {
    visto[v] = true;
    if (g[v].size() != 2) {
        es_ciclo = false;
    }
    for (auto u : g[v]) {
        if (!visto[u]) {
            dfs(u, g, es_ciclo);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    long long cont = 0;

    for (int i = 0; i < n; i++) {
        if (!visto[i]) {
            bool es_ciclo = true;
            dfs(i, g, es_ciclo);
            if (es_ciclo) cont++;
        }
    }

    cout << cont << "\n";
    return 0;
}



// F - Counting Rooms - CSES


#include <bits/stdc++.h>
using namespace std;


void bfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &a) {
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || a[i][j] == '#')
        return;

    vis[i][j] = true;

    bfs(i - 1, j, n, m, vis, a);
    bfs(i + 1, j, n, m, vis, a);
    bfs(i, j - 1, n, m, vis, a);
    bfs(i, j + 1, n, m, vis, a);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                bfs(i, j, n, m, vis, a);
                maxi++;
            }
        }
    }

    cout << maxi << "\n";
    return 0;
}



// G - Building Roads - CSES

#include <bits/stdc++.h>
using namespace std;


const int MAXN=1e5+5;

vector <bool> visto(MAXN,false);

void dfs(int v, vector <vector<int>> &g){
    visto[v]=true;
    for(auto u : g[v]) if(!visto[u]) dfs(u,g);
}

int main()
{
    int n, m; cin >> n >> m;
    vector <vector<int>> g(n);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cont=0;
    vector <int> vertices;
    for(int i=0; i<n; i++) if(!visto[i]){
        vertices.push_back(i);
        dfs(i,g);
        cont++;
    }
    cout << cont-1 << "\n";
    for(int i=1; i<cont; i++) cout << vertices[0]+1 << " " << vertices[i]+1 << "\n";
    return 0;
}


//H - Pipshas

#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

int dfs(int v, const vector<vector<int>> &g, vector<bool> &visto) {
    visto[v] = true;
    int gustos = 1;
    for (int u : g[v]) {
        if (!visto[u]) {
            gustos += dfs(u, g, visto);
        }
    }
    return gustos;
}

int main() {


    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> visto(n, false);
    long long result = 1;


    for (int i = 0; i < n; i++) {
        if (!visto[i]) {
            int gustos = dfs(i, g, visto);
            result = result * gustos % MOD;
        }
    }

    cout << result << "\n";
    return 0;
}

