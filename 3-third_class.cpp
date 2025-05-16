//To see the problems

//https://codeforces.com/group/roU9OApnmM/contest/604606



// A - Brightness Begins

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
int main() {
 
    FIN;
    int T;
    cin >> T;
    while (T--) {
        long long k;
        cin >> k;
 
 
        long long l = 0, r = 2000000000;
        while (l < r) {
            long long mid = l + (r - l) / 2;
 
            if (mid >= (k + mid) / (mid + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        long long s = l;
 
        cout << (k + s) << "\n";
    }
 
    return 0;
}


// B - Ecuación

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
int main() {
 
    FIN;
    double c;
    cin >> c;
 
    double res,mid=0, l=0, r=c*c;
 
    for (int i=0;i<100;i++){
        mid= (l+r)/2;
        res = mid*mid + sqrt(mid);
 
        if (res<c){
          l=mid;
        }
        else{
          r=mid;
        }
 
    }
     // Salida con precisión requerida
    cout << fixed << setprecision(10) << (l + r) / 2.0 << '\n';
    return 0;
}


// C - Limited Repainting

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
 
int main() {
    FIN;
    int t;
    cin >> t;
 
    int n, k_op, maxi;
    string s;
    vector<long long> penalty; // Se declara fuera, pero se redimensiona adentro
 
    for (int i = 0; i < t; i++) {
        // Leo
        cin >> n >> k_op;
        cin >> s;
        penalty.resize(n);
        maxi = -1;
        for (int j = 0; j < n; j++) {
            cin >> penalty[j];
            if (penalty[j] > maxi) {
                maxi = penalty[j];
            }
        }
 
        long long l = 0, r = maxi;
 
        while (l < r) {
            long long mid = (r + l) / 2;
 
            // Busco operaciones mínimas
            int ops = 0;
            int k = 0;
            while ((k < n) && (ops <= k_op)) {
                if (s[k] == 'B' && penalty[k] > mid) {
                    ops++;
                    while (k < n && !(s[k] == 'R' && penalty[k] > mid)) {
                        k++;
                    }
                } else {
                    k++;
                }
            }
 
            if (ops <= k_op) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
 
        cout << l << "\n";
    }
 
    return 0;
}

// D - Tralalero Tralala

#include <bits/stdc++.h>
 
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
 
using namespace std;
 
long long n_of_inversion = 0;
 
void mergesort(vector <int> &a) {
if(a.size() <= 1) return;
 
int n = int(a.size());
vector <int> l, r;
for(int i = 0; i < n/2; i++) l.push_back(a[i]);
for(int i = n/2; i < n; i++) r.push_back(a[i]);
 
vector <int> copia = a;
 
a.clear();
 
mergesort(l);
mergesort(r);
 
int posl = 0, posr = 0;
while(posl < l.size() and posr < r.size()) {
if(l[posl] <= r[posr]) {
a.push_back(l[posl]);
posl += 1;
} else {
n_of_inversion += l.size() - posl;
a.push_back(r[posr]);
posr += 1;
}
}
for(int i = posl; i < l.size(); i++) a.push_back(l[i]);
for(int i = posr; i < r.size(); i++) a.push_back(r[i]);
 
 
return;
}
 
int main() {
FIN;
 
int n; cin >> n;
vector <int> v(n);
for(int i = 0; i < n; i++) cin >> v[i];
 
 
 
mergesort(v);
 
cout << n_of_inversion << "\n";
 
 
 
return 0;
}


// E - Painting Fence

#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
 
long long resolver(int left, int right, long long base, const vector<long long>& v) {
 
    if (left >= right) return 0;
 
    int minIndex = left;
    for (int i = left + 1; i < right; ++i) {
        if (v[i] < v[minIndex]) {
            minIndex = i;
        }
    }
 
    long long costVertical = right - left;
    long long costHorizontal = v[minIndex] - base;
 
 
    costHorizontal += resolver(left, minIndex, v[minIndex], v);
    costHorizontal += resolver(minIndex + 1, right, v[minIndex], v);
 
    return min(costVertical, costHorizontal);
}
 
 
 
 
 
int main() {
 
    FIN;
    int n;
    long long res;
 
    cin >>n;
 
    vector<long long> v(n);
    for (int i=0;i<n; i++){
        cin>>v[i];
    }
 
    res = resolver(0, n, 0,v);
 
    cout << res;
 
 
    return 0;
}


// F - A Sorting Problem


#include <bits/stdc++.h>
 
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
 
using namespace std;
 
long long n_of_inversion = 0;
 
void mergesort(vector <int> &a) {
if(a.size() <= 1) return;
 
int n = int(a.size());
vector <int> l, r;
for(int i = 0; i < n/2; i++) l.push_back(a[i]);
for(int i = n/2; i < n; i++) r.push_back(a[i]);
 
vector <int> copia = a;
 
a.clear();
 
mergesort(l);
mergesort(r);
 
int posl = 0, posr = 0;
while(posl < l.size() and posr < r.size()) {
if(l[posl] <= r[posr]) {
a.push_back(l[posl]);
posl += 1;
} else {
n_of_inversion += l.size() - posl;
a.push_back(r[posr]);
posr += 1;
}
}
for(int i = posl; i < l.size(); i++) a.push_back(l[i]);
for(int i = posr; i < r.size(); i++) a.push_back(r[i]);
 
 
return;
}
 
int main() {
FIN;
 
int n; cin >> n;
vector <int> v(n);
for(int i = 0; i < n; i++) cin >> v[i];
 
 
 
mergesort(v);
 
cout << n_of_inversion << "\n";
 
 
 
return 0;
}

// G - Interview




#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0)
 
int main() {
    FIN;
    int tests;
    cin >> tests;
 
    for (int t = 0; t < tests; t++) {
        int n;
        cin >> n;
        vector<int> pilas(n);
 
        for (int i = 0; i < n; i++) cin >> pilas[i];
 
        vector<int> sum(n);
        sum[0] = pilas[0];
 
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + pilas[i];
 
        int l = 0, r = n, mid, query_sum;
 
        while (r - l > 1) {
            mid = (l + r) / 2;
            cout << "? " << mid;
            for (int i = 0; i < mid; i++) cout << " " << i + 1;
            cout << endl;
            cin >> query_sum;
            if (query_sum > sum[mid - 1]) r = mid;
            else l = mid;
        }
        cout << "! " << r << endl;
    }
    return 0;
}

// 	H - Guess the K-th Zero (Easy version)


#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0); cin.tie(0)
 
int main() {
    FIN;
    int n, t;
    cin >> n >> t;
 
    while (t--) {
 
        int k;
        cin >> k;
 
        int l = 0, r = n, rta, tot;
        while (r - l > 1) {
 
            int mid = (l + r) / 2;
            cout << "? " << l + 1 << " " << mid << endl;
            cin >> rta;
 
            tot = (mid - l) - rta;
            if (tot >= k)
                r = mid;
            else {
                k -= tot;
                l = mid;
            }
        }
        cout << "! " << r << endl;
    }
    return 0;
}





