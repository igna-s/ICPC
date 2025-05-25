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
