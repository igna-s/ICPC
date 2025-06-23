//https://cses.fi/problemset/     (Range Queries)


//Repasinho

/*

Estructura                  Uso principal                    Construcción    Consulta       Actualización    Espacio      Notas
--------------------------- -------------------------------- --------------------------------------------     ------------
Prefix Sum Array           Sumas de rango estáticas         O(n)            O(1)           O(n)             O(n)         Muy simple; no dinámico
Sqrt Decomposition         Consultas + updates moderados    O(n)            O(√n)          O(1)             O(n)         Fácil de implementar
Sparse Table               RMQ/min/max estático             O(n·log n)      O(1)           —                O(n·log n)   Sólo idempotentes, sin updates
Segment Tree               Consultas + updates rápidos      O(n)            O(log n)       O(log n)         O(n)         Versátil; admite casi cualquier f(range)


1. Prefix Sum Array (Arreglo de sumas acumuladas)

Uso: Cuando sólo necesitas consultas de rango (por ejemplo, suma de A[l…r]), sin actualizaciones intermedias.
Construcción: Precomputas P[i] = A[0] + … + A[i] en O(n).
Consulta: Suma rango en O(1): sum(l,r) = P[r] - (l>0 ? P[l-1] : 0).
Actualización: No admite bien actualizaciones; si cambias un elemento debes recomputar todo (O(n)).

2. Square Root Decomposition (Descomposición por raíz cuadrada)

Uso: Cuando quieres algo más dinámico que prefix sums, con actualizaciones y consultas, y prefieres implementarlo rápido.
Bloques: Divides en bloques de tamaño ≈√n.
Construcción: Preprocesas sumas parciales por bloque en O(n).
Consulta: O(√n) por combinar bloques completos + extremos parciales.
Actualización: O(1) para actualizar elemento y su bloque, o O(1)–O(√n) según el problema.

3. Sparse Table

Uso: Para consultas idempotentes en arreglos estáticos (RMQ, min, max, gcd…), sin actualizaciones.
Construcción: O(n log n) con DP de potencias de 2.
Consulta: O(1) usando dos superposiciones de intervalos.
Actualización: No admite: si cambias datos debes reconstruir (O(n log n)).

4. Segment Tree (Árbol de segmentos)

Uso: Cuando necesitas consultas y actualizaciones frecuentes en rangos (suma, mínimo, máximo, etc.).
Construcción: O(n)–O(n log n) según implementación.
Consulta: O(log n) por recorrer ramas.
Actualización: O(log n) para modificar hoja y propagar arriba.
Espacio: O(4 n) normalmente.




Note: Some of the exercises were made by the teacher
*/

//Static Range Sum Queries (Prefix Sum)

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
const long long NEUTRO = 0;
long long op(long long a, long long b){ return a + b; }
 
struct PrefixSum {
    int n;
    vector<long long> ps;
    PrefixSum(const vector<long long>& a): n(a.size()), ps(n+1, NEUTRO) {
        for(int i = 0; i < n; i++) ps[i+1] = op(ps[i], a[i]);
    }
    long long query(int l, int r) { return ps[r+1] - ps[l]; }
};
 
int main(){
    FIN;
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    PrefixSum ps(a);
    while(q--){
        int l, r; cin >> l >> r; l--, r--;
        cout << ps.query(l, r) << "\n";
    }
    return 0;
}




//Static Range Minimum Queries (Sparse Table)


#include <bits/stdc++.h>
 
using namespace std;
 
#define FIN ios::sync_with_stdio(0); cout.tie(0); cin.tie(0)
 
const int LOG = 20;
 
struct SparseTable {
    vector<vector<int>> s;
    int n;
 
    SparseTable(vector<int> &v, int _n) {
        n = _n;
        s.resize(n);
        for (int i = 0; i < n; i++) {
            s[i].resize(LOG);
        }
        for (int j = 0; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (j == 0) {
                    s[i][j] = v[i];
                } else {
                    s[i][j] = s[i][j - 1];
                    if (i + (1 << (j - 1)) < n) {
                        s[i][j] = min(s[i][j], s[i + (1 << (j - 1))][j - 1]);
                    }
                }
            }
        }
    }
 
    void imprimir() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < LOG; j++) {
                cerr << s[i][j] << " ";
            }
            cerr << endl;
        }
    }
 
    int query(int l, int r) {
        int ans = 1e9 + 7;
        int ancho = r - l + 1;
        for (int j = LOG - 1; j >= 0; j--) {
            if ((1 << j) <= ancho) {
                ans = min(ans, s[l][j]);
                l += (1 << j);
                ancho -= (1 << j);
            }
        }
        return ans;
    }
};
 
int main() {
    FIN;
 
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    SparseTable s(v, n);
    // s.imprimir();
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << s.query(l, r) << "\n";
    }
 
    return 0;
}


// Dynamic Range Sum Queries (Segment Tree)

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
const long long NEUTRO = 0;
long long op(long long a, long long b){ return a + b; }
 
struct SegmentTree {
    int n;
    vector<long long> st;
    SegmentTree(const vector<long long>& a) {
        int sz = a.size();
        for(n = 1; n < sz; n <<= 1);
        st.assign(2*n, NEUTRO);
        for(int i = 0; i < sz; i++) st[n+i] = a[i];
        for(int i = n-1; i >= 1; i--) st[i] = op(st[2*i], st[2*i+1]);
    }
    void update(int pos, long long val) {
        for(int p = pos + n; p >= 1; p >>= 1)
            if(p == pos + n) st[p] = val;
            else st[p] = op(st[2*p], st[2*p+1]);
    }
    long long query(int l, int r) {
        long long resL = NEUTRO, resR = NEUTRO;
        for(int L = l + n, R = r + n; L <= R; L >>= 1, R >>= 1) {
            if(L & 1) resL = op(resL, st[L++]);
            if(!(R & 1)) resR = op(st[R--], resR);
        }
        return op(resL, resR);
    }
};
 
int main(){
    FIN;
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    SegmentTree st(a);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int pos; long long val; cin >> pos >> val;
            st.update(pos-1, val);
        } else {
            int l, r; cin >> l >> r;
            cout << st.query(l-1, r-1) << "\n";
        }
    }
    return 0;
}





