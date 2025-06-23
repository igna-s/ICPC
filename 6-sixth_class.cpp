//https://cses.fi/problemset/     (Range Queries)


//Some notes (Spanish)

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


//Dynamic Range Minimum Queries (Square Root Descomposition)


#include <bits/stdc++.h>
 
using namespace std;
 
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
 
#ifdef LOCAL
const int MAXN = 100;
#else
const int MAXN = 2e5 + 5;
#endif
 
typedef long long ll;
const int BLOCKSIZE = 450;
const int LOG = 20;
const int BASE = 1e9 + 7;
 
 
struct block {
    int l, r, ans;
    block(int _l, int _r) {
        l = _l;
        r = _r;
        ans = 0;
    }
};
 
struct segment_block {
    vector<int> v;
    vector<block> t;
    int n;
 
    int op(int a, int b) {
        return min(a, b);
    }
 
    block refresh(block b) {
        b.ans = BASE; // Reinicia con el valor neutro
        for (int i = b.l; i < min(n, b.r); i++) {
            b.ans = op(b.ans, v[i]);
        }
        return b;
    }
 
    segment_block(vector<int> _v, int _n) {
        v = _v;
        n = _n;
        int tam = 0;
        int sz = 0;
        while (tam < n) {
            t.push_back(block(tam, tam + BLOCKSIZE));
            t[sz] = refresh(t[sz]);
            sz++;
            tam += BLOCKSIZE;
        }
    }
 
    void update(int pos, int val) {
        int id = pos / BLOCKSIZE;
        v[pos] = val;
        t[id] = refresh(t[id]);
    }
 
    ll query(int l, int r) {
        ll ans = BASE;
        for (block b: t) {
 
            if (r < b.l or l >= b.r) continue;
            if (l <= b.l and b.r - 1 <= r) {
                ans = op(ans, b.ans);
                continue;
            }
            for (int i = max(b.l, l); i <= min(r, b.r - 1); i++) {
                ans = op(ans, v[i]);
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
    for (int i = 0; i < n; i++) cin >> v[i];
 
    segment_block sb(v, n);
 
    for (int qq = 0; qq < q; qq++) {
        int op;
        cin >> op;
        if (op == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            sb.update(k, u);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << sb.query(l, r) << "\n";
        }
    }
 
    return 0;
}



//Range Xor Queries 


#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
const long long NEUTRO = 0;
long long op(long long a, long long b){ return (a ^ b); }
 
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
 
    int n, q;
    cin >> n >> q;
 
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree st(a);
 
 
    while(q--){
 
        int l, r;
        cin >> l >> r;
        cout << st.query(l - 1, r - 1) << "\n";
    }
 
    return 0;
}



//Range Update Queries



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
 
    void add(int pos, long long val) {
        pos += n;
        st[pos] += val;
        while (pos > 1) {
            pos >>= 1;
            st[pos] = op(st[2*pos], st[2*pos+1]);
        }
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
 
    vector<long long> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
 
    vector<long long> d(n + 1, 0);
 
    d[0] = x[0];
    for(int i = 1; i < n; i++) d[i] = x[i] - x[i-1];
    SegmentTree st(d);
 
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int a, b; long long u; cin >> a >> b >> u;
            st.add(a - 1, u);
            if (b < n) {
                st.add(b, -u);
            }
        } else {
            int k; cin >> k;
 
            cout << st.query(0, k - 1) << "\n";
        }
    }
 
    return 0;
}




//Forest Queries


#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
int main(){
    FIN;
    int n, q;
    cin >> n >> q;
 
    vector<string> bosque(n+1);
    for(int i = 1; i <= n; i++){
        cin >> bosque[i];
        bosque[i] = " " + bosque[i];  // desplazamos para indexar desde 1
    }
 
    vector<vector<int>> ps(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ps[i][j] = (bosque[i][j] == '*')
                     + ps[i-1][j]
                     + ps[i][j-1]
                     - ps[i-1][j-1];
        }
    }
 
    while(q--){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int ans = ps[y2][x2]
                - ps[y1-1][x2]
                - ps[y2][x1-1]
                + ps[y1-1][x1-1];
        cout << ans << "\n";
    }
 
    return 0;
}




//Hotel Queries


#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
vector<ll> st;
vector<ll> habitaciones_iniciales;
int n_hoteles;
 
void build(int v, int tl, int tr) {
    if (tl == tr) {
        st[v] = habitaciones_iniciales[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        st[v] = max(st[v * 2], st[v * 2 + 1]);
    }
}
 
void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        st[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        st[v] = max(st[v * 2], st[v * 2 + 1]);
    }
}
 
int find_first(int v, int tl, int tr, int r) {
    if (st[v] < r) {
        return -1;
    }
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) / 2;
    int res = -1;
    if (st[v * 2] >= r) {
        res = find_first(v * 2, tl, tm, r);
    }
    if (res == -1) {
        res = find_first(v * 2 + 1, tm + 1, tr, r);
    }
    return res;
}
 
int main() {
    FIN;
 
    int m_grupos;
    cin >> n_hoteles >> m_grupos;
 
    habitaciones_iniciales.resize(n_hoteles);
    for (int i = 0; i < n_hoteles; ++i) {
        cin >> habitaciones_iniciales[i];
    }
 
    st.resize(4 * n_hoteles);
    build(1, 0, n_hoteles - 1);
 
    for (int i = 0; i < m_grupos; ++i) {
        int r;
        cin >> r;
 
        int idx_hotel = find_first(1, 0, n_hoteles - 1, r);
 
        if (idx_hotel == -1) {
            cout << 0 << " ";
        } else {
            cout << idx_hotel + 1 << " ";
            habitaciones_iniciales[idx_hotel] -= r;
            update(1, 0, n_hoteles - 1, idx_hotel, habitaciones_iniciales[idx_hotel]);
        }
    }
 
    cout << "\n";
    return 0;
}




